import React, { useState, useEffect } from 'react';

function DegreeList() {
    const [degrees, setDegrees] = useState([]);

  useEffect(() => {
    fetch('http://127.0.0.1:8000/api/degree/')
      .then(response => response.json())
      .then(data => setDegrees(data))
      .catch(error => console.error(error));
  }, []);

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-2xl mx-auto">
        <h1 className="text-2xl font-semibold mb-6">All Degrees</h1>
        <table className="w-full border-collapse">
          <thead>
            <tr className="text-left">
              <th className="border-b-2 border-indigo-500 pb-2">Shortcode</th>
              <th className="border-b-2 border-indigo-500 pb-2">Full Name</th>
            </tr>
          </thead>
          <tbody>
            {degrees.map((degree) => (
              <tr key={degree.shortcode} className="odd:bg-indigo-100">
                <td className="border-b border-indigo-300 py-2">{degree.shortcode}</td>
                <td className="border-b border-indigo-300 py-2">{degree.full_name}</td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </div>
  );
}

export default DegreeList;