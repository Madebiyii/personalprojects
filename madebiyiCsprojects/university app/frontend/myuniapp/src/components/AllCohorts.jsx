import React, { useState, useEffect } from 'react';

const AllCohorts = () => {
  const [cohorts, setCohorts] = useState([]);

  useEffect(() => {
    async function fetchData() {
      const response = await fetch('http://127.0.0.1:8000/api/cohort/');
      const data = await response.json();
      setCohorts(data);
    }

    fetchData();
  }, []);

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-semibold mb-6">All Cohorts</h1>
        <ul>
          {cohorts.map((cohort) => (
            <li key={cohort.id} className="py-2 border-b border-gray-200">
              {cohort.name}
            </li>
          ))}
        </ul>
      </div>
    </div>
  );
};

export default AllCohorts;