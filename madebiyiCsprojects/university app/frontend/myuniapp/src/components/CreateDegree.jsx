import React, { useState } from 'react';

const CreateDegree = () => {
  const [fullName, setFullName] = useState('');
  const [shortCode, setShortCode] = useState('');
  const [error, setError] = useState(null);
  const [success, setSuccess] = useState(null);

  const handleSubmit = async (event) => {
    event.preventDefault();
    setError(null);
    setSuccess(null);

    try {
      const response = await fetch('http://127.0.0.1:8000/api/degree/', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          full_name: fullName,
          shortcode: shortCode,
        }),
      });

      if (!response.ok) {
        throw new Error('Error creating degree');
      }

      const degree = await response.json();
      setSuccess(`Degree "${degree.full_name}" created successfully.`);
      setFullName('');
      setShortCode('');
    } catch (error) {
      setError(`Error creating degree. Please try again.`);
    }
  };

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-semibold mb-6">Create a new degree</h1>
        <form onSubmit={handleSubmit} className="space-y-4">
          <label className="block">
            Full name:
            <input
              type="text"
              value={fullName}
              onChange={(event) => setFullName(event.target.value)}
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <label className="block">
            Short code:
            <input
              type="text"
              value={shortCode}
              onChange={(event) => setShortCode(event.target.value)}
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <button
            type="submit"
            className="w-full py-2 px-4 bg-indigo-600 text-white rounded-md hover:bg-indigo-700"
          >
            Create Degree
          </button>
        </form>
        {error && (
          <p className="mt-4 text-center text-red-600">{error}</p>
        )}
        {success && (
          <p className="mt-4 text-center text-green-600">{success}</p>
        )}
      </div>
    </div>
  );
};

export default CreateDegree;
