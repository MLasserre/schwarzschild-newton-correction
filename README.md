## 🪐 *Physical interpretation of the correction to Newton’s law by Schwarzschild metric*

This project was carried out during my first year of Master's studies.

It investigates how General Relativity corrects Newton’s law of gravitation through
the Schwarzschild metric.

After introducing the foundational concepts of General Relativity (equivalence
principle, geodesics, Einstein’s field equations), the report derives the
Schwarzschild solution and shows how it leads to a relativistic correction to
Newtonian gravity. This correction explains phenomena such as the
**perihelion precession of Mercury**, which classical mechanics cannot fully
account for.

The project includes an **analytical study** of the corrected equations and a
**numerical simulation** of Mercury's orbit using **Runge–Kutta methods**, 
in **C**.

---

## 🧪 Running the Simulation

To reproduce the numerical experiment on Mercury's orbit:

### 1. Go to the `simulation/` directory
```bash
cd simulation/
```

### 2. Compile the code
Make sure you have a C compiler installed (e.g., `gcc`), then run:
```bash
make
```

### 3. Run the simulation

- For the **classical Newtonian** version:
  ```bash
  ./simulation < parametres.in
  ```

- For the **relativistic corrected** version:
  ```bash
  ./simulation < parametres_precession.in
  ```

> The files `parametres.in` and `parametres_precession.in` provide default values
for the simulation, but feel free to edit them to explore different initial
conditions (e.g., time step, number of steps, etc.).

---

## 📈 Plotting the Results

After running the simulation, plot the results using **Scilab**:

```bash
scilab -nw -f tracer-sol.sce
```

This script reads the simulation output and plots the orbit.


### 🔎 View the full report

[📄 **Read the full PDF**](report.pdf)

