# Exponential Regression with Linearization

## Overview
This project demonstrates how to estimate parameters of a nonlinear exponential growth model:

y = a * exp(bx)

using linear regression after a mathematical transformation.

By applying the natural logarithm:

ln(y) = ln(a) + b * x

The nonlinear model becomes linear in terms of ln(y) and x. This allows the use of ordinary least squares regression to estimate the parameters a and b.

---

## Steps Implemented
The program is divided into six logical parts:

1. **Define problem**  
   - Set up the nonlinear exponential growth model.  
   - Specify the true parameters a and b.  

2. **Show linearisation with example**  
   - Demonstrate how taking ln(y) turns the model into a linear relationship.  
   - Provide an example calculation for verification.  

3. **Perform regression calculation**  
   - Generate synthetic data points with small random noise.  
   - Apply linear regression to the transformed data (x, ln(y)).  

4. **Present estimated parameters**  
   - Convert regression results back into original form (a, b).  
   - Print both true and estimated model equations.  

5. **Validate results**  
   - Calculate fitted values and residuals for each data point.  
   - Compute RMSE (Root Mean Squared Error) to measure accuracy.  

6. **Final conclusion**  
   - Interpret the RMSE and print whether the fit is Excellent, Good, or Weak.  

---

## Code Structure
- `define_problem` – sets problem size and true parameters.  
- `show_linearisation_example` – explains the transformation with an example.  
- `perform_regression` – generates synthetic data and performs regression.  
- `present_estimated_parameters` – prints true vs estimated parameters.  
- `validate_results` – outputs residuals and RMSE.  
- `final_conclusion` – interprets the fit quality.  
- `main` – integrates all steps in sequence.  

---
