import React, { useState, useEffect } from 'react';

const CohortModules = () => {
  const [cohortId, setCohortId] = useState('');
  const [cohorts, setCohorts] = useState([]);
  const [modules, setModules] = useState([]);

  useEffect(() => {
    async function fetchCohorts() {
      const response = await fetch('http://127.0.0.1:8000/api/cohort/');
      const data = await response.json();
      setCohorts(data);
    }

    fetchCohorts();
  }, []);

  useEffect(() => {
    if (!cohortId) return;

    async function fetchModules() {
      const response = await fetch(`http://127.0.0.1:8000/api/module/?delivered_to=${cohortId}`);
      const data = await response.json();
      setModules(data);
    }

    fetchModules();
  }, [cohortId]);

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-semibold mb-4">Modules for Cohort</h1>
        <div className="mb-6">
          <label className="block text-sm font-medium text-gray-700">Cohort:</label>
          <select
            value={cohortId}
            onChange={(e) => setCohortId(e.target.value)}
            required
            className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm py-2 px-3 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
          >
            <option value="">Select Cohort</option>
            {cohorts.map((cohort) => (
              <option key={cohort.id} value={cohort.id}>
                {cohort.name}
              </option>
            ))}
          </select>
        </div>
        
        <ul>
          {modules.map((module) => (
            <li key={module.code} className="py-2 border-b border-gray-200">
              {module.name} ({module.code})
            </li>
          ))}
        </ul>
      </div>
    </div>
  );
};

export default CohortModules;