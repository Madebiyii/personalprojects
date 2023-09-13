import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import './App.css';
import Homepage from './components/Homepage';
import DegreeList from './components/DegreeList';
import SingleDegree from './components/SingleDegree';
import CreateDegree from './components/CreateDegree';
import AllCohorts from './components/AllCohorts';
import SingleCohort from './components/SingleCohort';
import CreateCohort from './components/CreateCohort';
import AllModules from './components/AllModules';
import SingleModule from './components/SingleModule';
import CohortModules from './components/CohortModules';
import CreateModule from './components/CreateModule';
import StudentInfo from './components/StudentInfo';
import CreateStudent from './components/CreateStudent';
import SetStudentGrade from './components/SetStudentGrade';
import Navbar from './components/Navbar';
import Footer from './components/Footer';



function App() {
  return (
    <Router>
      <div className="App">
      <Navbar />
        <Routes>
          <Route path="/" element={<Homepage />} index />
          <Route path="/degree-list" element={<DegreeList />} />
          <Route path="/single-degree" element={<SingleDegree />} />
          <Route path="/create-degree" element={<CreateDegree />} />
          <Route path="/cohorts" element={<AllCohorts />} />
          <Route path="/single-cohort" element={<SingleCohort />} />
          <Route path="/create-cohort" element={<CreateCohort />} />
          <Route path="/modules" element={<AllModules />} />
          <Route path="/single-module" element={<SingleModule />} />
          <Route path="/cohort-modules" element={<CohortModules />} />
          <Route path="/create-module" element={<CreateModule />} />
          <Route path="/individual-student" element={<StudentInfo />} />
          <Route path="/create-student" element={<CreateStudent />} />
          <Route path="/set-student-grade" element={<SetStudentGrade />} />

        </Routes>
      </div>
      <Footer />
    </Router>
  );
}

export default App;

