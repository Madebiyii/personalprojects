import React, { useState, useEffect } from 'react';

const StudentInfo = () => {
  const [students, setStudents] = useState([]);
  const [student, setStudent] = useState(null);
  const [cohort, setCohort] = useState(null);
  const [grades, setGrades] = useState([]);
  const [selectedStudentNumber, setSelectedStudentNumber] = useState('');

  useEffect(() => {
    async function fetchStudents() {
      const response = await fetch('http://127.0.0.1:8000/api/student/');
      const data = await response.json();
      setStudents(data);
    }

    fetchStudents();
  }, []);

  useEffect(() => {
    if (!selectedStudentNumber) return;

    async function fetchStudent() {
      const response = await fetch(`http://127.0.0.1:8000/api/student/?student_id=${selectedStudentNumber}`);
      const data = await response.json();
      setStudent(data[0]);
      await fetchCohort(data[0].cohort);
    }

    async function fetchCohort(url) {
      const response = await fetch(url);
      const data = await response.json();
      setCohort(data.name);
    }

    async function fetchGrades() {
      const response = await fetch(`http://127.0.0.1:8000/api/grade/?student=${selectedStudentNumber}`);
      const data = await response.json();
      setGrades(data);
    }

    fetchStudent();
    fetchGrades();
  }, [selectedStudentNumber]);

  const extractModuleName = (url) => {
    const parts = url.split('/');
    return parts[parts.length - 2];
  };


  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-bold mb-4 text-gray-800">Student Information</h1>
        <div className="mb-4">
          <label className="block text-sm font-medium text-gray-700">Student Number:</label>
          <select
            value={selectedStudentNumber}
            onChange={(e) => setSelectedStudentNumber(e.target.value)}
            required
            className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm py-2 px-3 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
          >
            <option value="">Select Student Number</option>
            {students.map((student) => (
              <option key={student.student_id} value={student.student_id}>
                {student.student_id}
              </option>
            ))}
          </select>
        </div>
        {student && (
          <div>
            <p className="text-gray-700 mb-2">Name: {student.first_name} {student.last_name}</p>
            <p className="text-gray-700 mb-2">Email: {student.email}</p>
            <p className="text-gray-700 mb-6">Cohort: {cohort}</p>

        
            
            <h2 className="text-xl font-semibold mb-4 text-gray-800">Registered Modules</h2>
        <ul className="list-disc list-inside mb-6 text-gray-700">
          {grades.map((grade) => (
            <li key={grade.module}>{extractModuleName(grade.module)}</li>
          ))}
        </ul>

            <h2 className="text-xl font-semibold mb-4 text-gray-800">Grades</h2>
            <table className="min-w-full divide-y divide-gray-200">
              <thead>
                <tr>
                  <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase">
                    Module
                  </th>
                  <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase">
                    Grade
                  </th>
                </tr>
              </thead>
              <tbody className="bg-white divide-y divide-gray-200">
                {grades.map((grade) => (
                  <tr key={grade.module}>
                    <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-500">
                      {extractModuleName(grade.module)}
                    </td>
                    <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-500">
                      {grade.total_grade}
                    </td>
                  </tr>
                ))}
              </tbody>
            </table>
          </div>
        )}
      </div>
    </div>
  );
};

export default StudentInfo;