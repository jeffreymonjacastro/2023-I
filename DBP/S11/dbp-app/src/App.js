import './css/App.css';
import { PrimerComp } from './components/PrimerComp';
import { SegundoComp } from './components/SegundoComp';

function App() {
  return (
    <div className="main">
      Hello World
      
      <PrimerComp />

      <hr />

      <SegundoComp />
    </div>
  )
}

export default App;
