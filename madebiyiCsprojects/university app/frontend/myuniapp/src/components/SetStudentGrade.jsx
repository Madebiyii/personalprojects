import React, { useState, useEffect} from 'react';

const SetStudentGrade = () => {
  const [students, setStudents] = useState([]);
  const [modules, setModules] = useState([]);
  const [selectedStudent, setSelectedStudent] = useState('');
  const [selectedModule, setSelectedModule] = useState('');
  const [grade, setGrade] = useState('');
  const [message, setMessage] = useState('');
  
  useEffect(() => {
    async function fetchData() {
      const studentResponse = await fetch('http://127.0.0.1:8000/api/student/');
      const studentData = await studentResponse.json();
      setStudents(studentData);
  
      const moduleResponse = await fetch('http://127.0.0.1:8000/api/module/');
      const moduleData = await moduleResponse.json();
      setModules(moduleData);
    }
  
    fetchData();
  }, []);
  


  const handleSubmit = async (e) => {
    e.preventDefault();

  
    setMessage('Grade updated successfully.');
  };

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-bold mb-4 text-gray-800">Set Student Grade for a Module</h1>
        <form onSubmit={handleSubmit}>
          <div className="mb-4">
            <label className="block text-sm font-medium text-gray-700">Student:</label>
            <select
              value={selectedStudent}
              onChange={(e) => setSelectedStudent(e.target.value)}
              required
              className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm py-2 px-3 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
            >
              <option value="">Select Student</option>
              {students.map((student, index) => (
                <option key={`${student.id}-${index}`} value={student.id}>
                  {student.first_name} {student.last_name}
                </option>
              ))}
            </select>
          </div>
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
                  {module.full_name}
                </option>
              ))}
            </select>
          </div>
          <div className="mb-4">
            <label className="block text-sm font-medium text-gray-700">Grade:</label>
            <input
              type="number"
              min="0"
              max="100"
              value={grade}
              onChange={(e) => setGrade(e.target.value)}
              required
              className="mt-1 block w-full border border-gray-300 rounded-md shadow-sm py-2 px-3 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
            />
          </div>
          <button
            type="submit"
            className="inline-flex justify-center py-2 px-4 border border-transparent shadow-sm text-sm font-medium rounded-md text-white bg-indigo-600 hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500"
          >
            Set Grade
          </button>
        </form>
        {message && <p className="mt-4 text-green-500">{message}</p>}
      </div>
    </div>
  );
  };

export default SetStudentGrade;