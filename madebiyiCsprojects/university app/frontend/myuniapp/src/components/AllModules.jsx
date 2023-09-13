import React, { useState, useEffect } from 'react';

const ModuleList = () => {
  const [modules, setModules] = useState([]);

  useEffect(() => {
    async function fetchModules() {
      const response = await fetch('http://127.0.0.1:8000/api/module/');
      const modulesData = await response.json();
      setModules(modulesData);
    }

    fetchModules();
  }, []);

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-semibold mb-6">Modules List</h1>
        <ul>
          {modules.map((module) => (
            <li key={module.id} className="py-2 border-b border-gray-200">
              {module.name} ({module.code})
            </li>
          ))}
        </ul>
      </div>
    </div>
  );
};

export default ModuleList;