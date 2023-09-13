import React, { useState } from 'react';

const CreateCohort = () => {
  const [id, setId] = useState('');
  const [year, setYear] = useState('');
  const [degree, setDegree] = useState('');
  const [name, setName] = useState('');
  const [message, setMessage] = useState('');

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      const response = await fetch('http://127.0.0.1:8000/api/cohort/', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({ id, year, degree, name }),
      });

      if (response.ok) {
        setMessage('Cohort created successfully.');
      } else {
        setMessage('Error creating cohort. Please try again.');
      }
    } catch (error) {
      setMessage('Error creating cohort. Please try again.');
    }
  };

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-semibold mb-6">Create New Cohort</h1>
        <form onSubmit={handleSubmit} className="space-y-4">
          <label className="block">
            ID:
            <input
              type="text"
              value={id}
              onChange={(e) => setId(e.target.value)}
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <label className="block">
            Year:
            <input
              type="number"
              value={year}
              onChange={(e) => setYear(e.target.value)}
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <label className="block">
            Degree URL:
            <input
              type="text"
              value={degree}
              onChange={(e) => setDegree(e.target.value)}
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <label className="block">
            Name:
            <input
              type="text"
              value={name}
              onChange={(e) => setName(e.target.value)}
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <button
            type="submit"
            className="w-full py-2 px-4 bg-indigo-600 text-white rounded-md hover:bg-indigo-700"
          >
            Create Cohort
          </button>
        </form>
        {message && (
          <p className="mt-4 text-center text-red-600">{message}</p>
        )}
      </div>
    </div>
  );
};

export default CreateCohort;