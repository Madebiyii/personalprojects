import React, { useState, useEffect } from 'react';

const SingleModule = () => {
  const [modules, setModules] = useState([]);
  const [module, setModule] = useState(null);
  const [selectedModule, setSelectedModule] = useState('');

  useEffect(() => {
    async function fetchModules() {
      const response = await fetch('http://127.0.0.1:8000/api/module/');
      const data = await response.json();
      setModules(data);
    }

    fetchModules();
  }, []);

  useEffect(() => {
    if (!selectedModule) return;

    async function fetchModule() {
      const response = await fetch(`http://127.0.0.1:8000/api/module/${selectedModule}/`);
      const moduleData = await response.json();
      setModule(moduleData);
    }

    fetchModule();
  }, [selectedModule]);

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-bold mb-4 text-gray-800">Module Information</h1>
        <div className="mb-4">
          <label className="block text-sm font-medium text-gray-700">Module:</label>
          <select
            value={selectedModule}
            onChange={(e) => setSelectedModule(e.target.value)}
            required
            className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm py-2 px-3 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
          >
            <option value="">Select Module</option>
            {modules.map((module) => (
              <option key={module.code} value={module.code}>
                {module.name} ({module.code})
              </option>
            ))}
          </select>
        </div>
        {module && (
          <>
            <p className="text-gray-700 mb-2">Module Full Name: {module.full_name}</p>
            <p className="text-gray-700">Ca Split: {module.ca_split}</p>
          </>
        )}
      </div>
    </div>
  );
};

export default SingleModule;