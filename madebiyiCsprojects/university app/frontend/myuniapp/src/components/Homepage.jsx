import React from 'react';

const Homepage = () => {
  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-2xl mx-auto">
        <h1 className="text-2xl font-semibold mb-6">Welcome to The University Portal</h1>
        <p className="text-gray-700">
          Here you can find out all about different modules, courses and students by clicking the appropriate link in the Navbar above.
        </p>
      </div>
    </div>
  );
};

export default Homepage;

