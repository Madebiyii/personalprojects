import React, { useState, useEffect } from 'react';

const SingleDegree = () => {
  const [degrees, setDegrees] = useState([]);
  const [cohorts, setCohorts] = useState([]);
  const [selectedDegree, setSelectedDegree] = useState('');

  useEffect(() => {
    async function fetchDegrees() {
      const degreeResponse = await fetch('http://127.0.0.1:8000/api/degree/');
      const degreeData = await degreeResponse.json();
      setDegrees(degreeData);
    }

    fetchDegrees();
  }, []);

  useEffect(() => {
    async function fetchCohorts() {
      if (selectedDegree) {
        const cohortResponse = await fetch(`http://127.0.0.1:8000/api/cohort/?degree=${selectedDegree}`);
        const cohortData = await cohortResponse.json();
        setCohorts(cohortData);
      }
    }

    fetchCohorts();
  }, [selectedDegree]);

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-bold mb-4 text-gray-800">Select Degree</h1>
        <div className="mb-4">
          <label className="block text-sm font-medium text-gray-700">Degree:</label>
          <select
            value={selectedDegree}
            onChange={(e) => setSelectedDegree(e.target.value)}
            required
            className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm py-2 px-3 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
          >
            <option value="">Choose a degree</option>
            {degrees.map((degree) => (
              <option key={degree.shortcode} value={degree.shortcode}>
                {degree.full_name}
              </option>
            ))}
          </select>
        </div>
        {cohorts.length > 0 && (
          <>
            <h2 className="text-xl font-semibold mb-2 text-gray-800">Cohorts</h2>
            <ul className="list-disc pl-5">
              {cohorts.map((cohort) => (
                <li key={cohort.id} className="mb-1 text-gray-700">
                  {cohort.name}
                </li>
              ))}
            </ul>
          </>
        )}
      </div>
    </div>
  );
};

export default SingleDegree;