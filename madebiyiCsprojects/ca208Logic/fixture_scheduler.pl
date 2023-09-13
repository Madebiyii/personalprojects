% Define the teams in each group
group(1, [team1, team2, team3, team4, team5]).
group(2, [team6, team7, team8, team9, team10]).
group(3, [team11, team12, team13, team14, team15]).
group(4, [team16, team17, team18, team19, team20]).
group(5, [team21, team22, team23, team24, team25]).
group(6, [team26, team27, team28, team29, team30]).

% Predicate to generate a schedule
schedule(S) :-
    findall((Group, A, B, Day),
            (between(1, 6, Group),
             group(Group, Teams),
             schedule_group(Group, Teams, Day, A, B)),
            S),
    valid_schedule(S).

% Predicate to schedule group matches
schedule_group(Group, Teams, Day, A, B) :-
    select(A, Teams, Teams1),
    select(B, Teams1, _),
    A \= B,
    atom_concat('team', ANumAtom, A),
    atom_concat('team', BNumAtom, B),
    atom_number(ANumAtom, ANum),
    atom_number(BNumAtom, BNum),
    Day is ((Group - 1) * 10) + (ANum - 1) * 5 + BNum.

% Check if a schedule is valid
valid_schedule(S) :-
    max_day_limit(S, 3),
    equal_home_away_fixtures(S),
    rest_days_between_fixtures(S, 4).

% Check if there are no more than MaxMatches matches on any day
max_day_limit(_, MaxMatches) :- MaxMatches =< 0, !, fail.
max_day_limit(S, MaxMatches) :-
    findall(Day, (member((_, _, _, Day), S)), Days),
    sort(Days, UniqueDays),
    \+ (member(D, UniqueDays),
        include(day_match(D), S, MatchesOnDay),
        length(MatchesOnDay, NumMatches),
        NumMatches > MaxMatches).

day_match(Day, (_, _, _, Day)).

% Check if each team has the same number of home and away fixtures in the whole schedule
equal_home_away_fixtures(S) :-
    findall(team(T), group(_, T), AllTeams),
    flatten(AllTeams, Teams),
    \+ (member(T, Teams),
        include(home_team(T), S, HomeMatches),
        include(away_team(T), S, AwayMatches),
        length(HomeMatches, HomeCount),
        length(AwayMatches, AwayCount),
        HomeCount \= AwayCount).

home_team(Team, (_, Team, _, _)).
away_team(Team, (_, _, Team, _)).

% Check if each team has at least MinRestDays rest days between fixtures
rest_days_between_fixtures(S, MinRestDays) :-
    findall(team(T), group(_, T), AllTeams),
    flatten(AllTeams, Teams),
    \+ (member(T, Teams),
        findall(Day, (member((_, T, _, Day), S) ; member((_, _, T, Day), S)), TeamDays),
        sort(TeamDays, SortedTeamDays),
        has_insufficient_rest(SortedTeamDays, MinRestDays)).

has_insufficient_rest([_], _).
has_insufficient_rest([D1, D2 | _], MinRestDays) :-
    D2 - D1 =< MinRestDays,
    !, fail.
has_insufficient_rest([_ | Rest], MinRestDays) :-
    has_insufficient_rest(Rest, MinRestDays).

% Main program to run the schedule generator
main :-
    schedule(S),
    sort(S, SortedSchedule),
    writeln(SortedSchedule).