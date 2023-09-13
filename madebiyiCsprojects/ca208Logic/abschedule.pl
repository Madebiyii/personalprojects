% Define the groups
group(1, [1,2,3,4,5]).
group(2, [6,7,8,9,10]).
group(3, [11,12,13,14,15]).
group(4, [16,17,18,19,20]).
group(5, [21,22,23,24,25]).
group(6, [26,27,28,29,30]).

% Define a game between two teams
game(TeamA, TeamB, Day, (TeamA, TeamB, Day)) :-
    TeamA < TeamB.

% Define a game between all teams in a group
games_in_group(Group, Day, Games) :-
    findall(Game, (member(TeamA, Group), member(TeamB, Group), TeamA < TeamB, game(TeamA, TeamB, Day, Game)), Games).

% Generate a valid schedule
schedule(Schedule) :-
    findall(Games, (group(_, Group), between(1, 6, Day), games_in_group(Group, Day, Games)), AllGames),
    append(AllGames, Games),
    valid_schedule(Games),
    generate_schedule(Games, 1, 0, Schedule),
    print_schedule(Schedule).

% Check if a schedule is valid
valid_schedule(Schedule) :-
    valid_games(Schedule),
    valid_days(Schedule),
    valid_rest_days(Schedule),
    valid_home_away_balance(Schedule).

% Check if the list of games in a schedule is valid
valid_games(Games) :-
    sort(Games, SortedGames),
    length(SortedGames, NumGames),
    NumGames =< 30,
    \+ (member((A,B,Day), SortedGames), member((A,B,Day2), SortedGames), Day \= Day2),
    \+ (member((A,B,Day), SortedGames), findall((A,B,DayX), member((A,B,DayX), SortedGames), Matches), length(Matches, Count), Count > 1).

% Check if the days in a schedule are valid
valid_days(Schedule) :-
    \+ (member(Day, [1,2,3,4,5,6]), findall(Game, member((_,_,Day), Schedule), Games), length(Games, Count), Count > 3).

% Check if each team has at least four rest days between fixtures
valid_rest_days(Schedule) :-
    all_teams(Teams),
    \+ (member(Team, Teams), team_rest_days_violation(Schedule, Team)).

team_rest_days_violation(Schedule, Team) :-
    findall(Day, (member((Team, _, Day), Schedule); member((_, Team, Day), Schedule)), Days),
    sort(Days, SortedDays),
    append([_, _, _, _, _], SortedDaysWithGap, SortedDays),
    append(SortedDaysWithGap, [_, _, _, _, _], SortedDays).

% Check if each team has the same number of home and away fixtures in the whole schedule
valid_home_away_balance(Schedule) :-
    all_teams(Teams),
    \+ (member(Team, Teams), home_away_difference(Schedule, Team, Diff), Diff =\= 0).

home_away_difference(Schedule, Team, Diff) :-
    aggregate(count, member((Team, _, _), Schedule), HomeCount),
    aggregate(count, member((_, Team, _), Schedule), AwayCount),
    Diff is HomeCount - AwayCount.

schedule_games([], []).
schedule_games([(A, B, _)|Rest], [(A, B)|Games]) :-
    schedule_games(Rest, Games).

generate_schedule([], _, _, []).
generate_schedule([(A, B)|Games], Day, DayMatches, [(A, B, Day)|Schedule]) :-
    DayMatches < 3,
    NextDayMatches is DayMatches + 1,
    generate_schedule(Games, Day, NextDayMatches, Schedule).

generate_schedule([Game|Games], Day, _, Schedule) :-
    NextDay is Day + 1,
    generate_schedule([Game|Games], NextDay, 0, Schedule).

valid_schedule(Schedule) :-
    valid_games(Schedule),
    valid_days(Schedule),
    valid_rest_days(Schedule),
    valid_home_away_balance(Schedule).

valid_games(Schedule) :-
    findall(Game, (group(_, Group), game_in_group(Group, Game)), Games),
    sort(Games, SortedGames),
    schedule_games(Schedule, ScheduledGames),
    sort(ScheduledGames, SortedGames).

valid_days(Schedule) :-
    \+ (setof(Day, A^B^(member((A, B, Day), Schedule)), Days),
        member(Day, Days),
        findall(_, member((_, _, Day), Schedule), Matches),
        length(Matches, Count),
        Count > 3).

valid_rest_days(Schedule) :-
    all_teams(Teams),
    \+ (member(Team, Teams), team_rest_days_violation(Schedule, Team)).

team_rest_days_violation(Schedule, Team) :-
    findall(Day, (member((Team, _, Day), Schedule); member((_, Team, Day), Schedule)), Days),
    sort(Days, SortedDays),
    append([_, _, _, _, _], SortedDaysWithGap, SortedDays),
    append(SortedDaysWithGap, [_, _, _, _, _], SortedDays).

valid_home_away_balance(Schedule) :-
    all_teams(Teams),
    \+ (member(Team, Teams), home_away_difference(Schedule, Team, Diff), Diff =\= 0).

all_teams(Teams) :-
    findall(Team, (group(_, Group), member(Team, Group)), AllTeams),
    sort(AllTeams, Teams).

game(TeamA, TeamB, Game) :-
    TeamA < TeamB,
    Game = (TeamA, TeamB).

game_in_group(Group, Game) :-
    member(TeamA, Group),
    member(TeamB, Group),
    game(TeamA, TeamB, Game).

schedule(Schedule) :-
    findall(Game, (group(_, Group), game_in_group(Group, Game)), Games),
    generate_schedule(Games, 1, 0, Schedule),
    valid_schedule(Schedule),
    format_schedule(Schedule).

format_schedule([]).
format_schedule([(A,B,Day)|Rest]) :-
    format('Day ~d: Team ~d vs Team ~d~n', [Day, A, B]),
    format_schedule(Rest).