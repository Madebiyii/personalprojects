import React from 'react';
import { Link, NavLink } from 'react-router-dom';

const Navbar = () => {
  return (
    <nav className="bg-gradient-to-r from-blue-600 via-purple-500 to-indigo-600 p-6 shadow-lg">
      <div className="container mx-auto flex justify-between items-center">
        <Link to="/" className="text-white font-semibold text-xl">
          The University Portal
        </Link>
        <div className="overflow-x-auto">
          <ul className="flex space-x-4 mt-2">
            {[
              { path: '/degree-list', title: 'Degree List' },
              { path: '/single-degree', title: 'Single Degree' },
              { path: '/create-degree', title: 'Create Degree' },
              { path: '/cohorts', title: 'Cohorts' },
              { path: '/single-cohort', title: 'Single Cohort' },
              { path: '/cohort-modules', title: 'Cohort Modules' },
              { path: '/create-cohort', title: 'Create Cohort' },
              { path: '/modules', title: 'Modules' },
              { path: '/single-module', title: 'Single Module' },
              { path: '/create-module', title: 'Create Module' },
              { path: '/create-student', title: 'Create Student' },
              { path: '/individual-student', title: 'View Individual Student' },
              { path: '/set-student-grade', title: 'Set Student Grade' },
            ].map(({ path, title }) => (
              <li key={path}>
                <NavLink
                  to={path}
                  activeClassName="bg-white text-blue-500 rounded"
                  className="text-white hover:text-blue-500 hover:bg-white hover:bg-opacity-20 px-2 py-1 rounded transition duration-300"
                >
                  {title}
                </NavLink>
              </li>
            ))}
          </ul>
        </div>
      </div>
    </nav>
  );
};

export default Navbar;



