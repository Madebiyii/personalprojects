import React, { useState, useEffect } from 'react';

const SingleCohort = () => {
  const [cohorts, setCohorts] = useState([]);
  const [cohort, setCohort] = useState(null);
  const [students, setStudents] = useState([]);
  const [selectedCohort, setSelectedCohort] = useState('');

  useEffect(() => {
    async function fetchCohorts() {
      const response = await fetch('http://127.0.0.1:8000/api/cohort/');
      const data = await response.json();
      setCohorts(data);
    }

    fetchCohorts();
  }, []);

  useEffect(() => {
    if (!selectedCohort) return;

    async function fetchData() {
      const cohortResponse = await fetch(`http://127.0.0.1:8000/api/cohort/${selectedCohort}`);
      const cohortData = await cohortResponse.json();
      setCohort(cohortData);

      const studentResponse = await fetch(`http://127.0.0.1:8000/api/student/?cohort=${selectedCohort}`);
      const studentData = await studentResponse.json();
      setStudents(studentData);
    }

    fetchData();
  }, [selectedCohort]);

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-bold mb-4 text-gray-800">Cohort Information</h1>
        <div className="mb-4">
          <label className="block text-sm font-medium text-gray-700">Cohort:</label>
          <select
            value={selectedCohort}
            onChange={(e) => setSelectedCohort(e.target.value)}
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
        {cohort && (
          <>
            <h2 className="text-xl font-semibold mb-2 text-gray-800">Students</h2>
            <ul className="list-disc pl-5">
              {students.map((student) => (
                <li key={student.student_id} className="mb-1 text-gray-700">
                  {student.first_name} {student.last_name} ({student.email})
                </li>
              ))}
            </ul>
          </>
        )}
      </div>
    </div>
  );
};

export default SingleCohort;