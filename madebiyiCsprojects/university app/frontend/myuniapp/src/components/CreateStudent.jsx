import React, { useState, useEffect } from 'react';

const CreateStudent = () => {

    const [cohorts, setCohorts] = useState([]);
    const [studentId, setStudentId] = useState('');
    const [firstName, setFirstName] = useState('');
    const [lastName, setLastName] = useState('');
    const [email, setEmail] = useState('');
    const [selectedCohort, setSelectedCohort] = useState('');
    const [selectedCohortId, setSelectedCohortId] = useState('');
  
    const [message, setMessage] = useState('');
  
    useEffect(() => {
      async function fetchCohorts() {
        const response = await fetch('http://127.0.0.1:8000/api/cohort/');
        const data = await response.json();
        setCohorts(data);
      }
  
      fetchCohorts();
    }, []);
  
    const handleCohortChange = (e) => {
      const { value } = e.target;
      setSelectedCohortId(value);
      setSelectedCohort(`http://127.0.0.1:8000/api/cohort/${value}/`);
    };
    
    
  
    const handleSubmit = async (e) => {
      e.preventDefault();
    
      const newStudent = {
        student_id: studentId,
        first_name: firstName,
        last_name: lastName,
        email,
        cohort: selectedCohort,
      };
    
      const response = await fetch('http://127.0.0.1:8000/api/student/', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(newStudent),
      });
    
      if (response.ok) {
        setMessage('Student created successfully.');
        setStudentId('');
        setFirstName('');
        setLastName('');
        setEmail('');
        setSelectedCohort('');
      } else {
        const errorDetails = await response.json();
        console.log(errorDetails);
        setMessage('Error creating student. Please try again.');
      }
    };
    

  return (
    <div className="container mx-auto px-4 py-8 min-h-screen bg-gradient-to-r from-blue-400 to-purple-400">
      <div className="bg-white shadow rounded p-6 max-w-xl mx-auto">
        <h1 className="text-2xl font-semibold mb-6">Create a New Student</h1>
        <form onSubmit={handleSubmit} className="space-y-4">
          <label className="block">
            Student ID:
            <input
              type="text"
              value={studentId}
              onChange={(e) => setStudentId(e.target.value)}
              required
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <label className="block">
            First Name:
            <input
              type="text"
              value={firstName}
              onChange={(e) => setFirstName(e.target.value)}
              required
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <label className="block">
            Last Name:
            <input
              type="text"
              value={lastName}
              onChange={(e) => setLastName(e.target.value)}
              required
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <label className="block">
            Email:
            <input
              type="email"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
              required
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            />
          </label>
          <label className="block">
            Cohort:
            <select
              value={selectedCohortId}
              onChange={handleCohortChange}
              required
              className="block w-full mt-1 border border-indigo-500 rounded-md focus:ring-indigo-500 focus:border-indigo-500"
            >
              <option value="">Select Cohort</option>
              {cohorts.map((cohort) => (
                <option key={cohort.id} value={cohort.id}>
                  {cohort.name}
                </option>
              ))}
            </select>
          </label>
          <button
            type="submit"
            className="w-full py-2 px-4 bg-indigo-600 text-white rounded-md hover:bg-indigo-700"
          >
            Create Student
          </button>
        </form>
        {message && (
          <p className="mt-4 text-center text-indigo-600">{message}</p>
        )}
      </div>
    </div>
  );
};

export default CreateStudent;