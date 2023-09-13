import React, { useState, useEffect } from 'react';

const CreateModule = () => {

const [cohorts, setCohorts] = useState([]);
const [code, setCode] = useState('');
const [fullName, setFullName] = useState('');
const [selectedCohorts, setSelectedCohorts] = useState([]);
const [caSplit, setCaSplit] = useState('');
const [message, setMessage] = useState('');

useEffect(() => {
  async function fetchCohorts() {
    const response = await fetch('http://127.0.0.1:8000/api/cohort/');
    const data = await response.json();
    setCohorts(data);
  }

  fetchCohorts();
}, []);

const handleSubmit = async (e) => {
  e.preventDefault();

  const deliveredToUrls = selectedCohorts.map(
    (cohortId) => `http://127.0.0.1:8000/api/cohort/${cohortId}/`
  );

  const newModule = {
    code,
    full_name: fullName,
    delivered_to: deliveredToUrls,
    ca_split: parseInt(caSplit),
  };

  const response = await fetch('http://127.0.0.1:8000/api/module/', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify(newModule),
  });

  if (response.ok) {
    setMessage('Module created successfully.');
    setCode('');
    setFullName('');
    setSelectedCohorts([]);
    setCaSplit('');
  } else {
    setMessage('Error creating module. Please try again.');
  }
};

const handleCohortChange = (e) => {
  const { value, checked } = e.target;
  if (checked) {
    setSelectedCohorts([...selectedCohorts, value]);
  } else {
    setSelectedCohorts(selectedCohorts.filter((cohort) => cohort !== value));
  }
};

return (
  <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
    <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
      <h1 className="text-2xl font-semibold mb-6">Create a New Module</h1>
      <form onSubmit={handleSubmit} className="space-y-4">
        <label className="block">
          Code:
          <input
            type="text"
            value={code}
            onChange={(e) => setCode(e.target.value)}
            required
            className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
          />
        </label>
        <label className="block">
          Full Name:
          <input
            type="text"
            value={fullName}
            onChange={(e) => setFullName(e.target.value)}
            required
            className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
          />
        </label>
        <label className="block">
          CA Split:
          <input
            type="number"
            value={caSplit}
            onChange={(e) => setCaSplit(e.target.value)}
            required
            className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
          />
        </label>
        <label className="block">
          Delivered to Cohorts:
          <div className="mt-2">
            {cohorts.map((cohort) => (
              <label key={cohort.id} className="inline-flex items-center mr-4 mb-2">
                <input
                  type="checkbox"
                  value={cohort.id}
                  onChange={handleCohortChange}
                  className="text-indigo-600 focus:ring-indigo-500 border-gray-300 rounded"
                />
                <span className="ml-2">{cohort.name}</span>
              </label>
            ))}
          </div>
        </label>
        <button
          type="submit"
          className="w-full py-2 px-4 bg-indigo-600 text-white rounded-md hover:bg-indigo-700"
        >
          Create Module
        </button>
      </form>
      {message && (
        <p className="mt-4 text-center text-indigo-600">{message}</p>
      )}
    </div>
  </div>
);
};

export default CreateModule;