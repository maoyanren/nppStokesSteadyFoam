// solver control
const dictionary& control = mesh.solutionDict().subDict("nppStokesSteadyControl");

bool fixNPP = control.lookupOrDefault("fixNPP",false);  // Can fix phiV and c if specified.

bool fixU = control.lookupOrDefault("fixU",false);

const int nNonOrthCorr = control.lookupOrDefault<int>("nNonOrthCorrectors", 0);

// specify convergence criteria for the fields

const dictionary& residualDict = mesh.solutionDict().subDict("residualControl");

const scalar c1ResTol = residualDict.lookupOrDefault<scalar>("c1Res", 1e-06);

const scalar c2ResTol = residualDict.lookupOrDefault<scalar>("c2Res", 1e-06);

const scalar phiVResTol = residualDict.lookupOrDefault<scalar>("phiVRes", 1e-06);

const scalar uResTol = residualDict.lookupOrDefault<scalar>("URes", 1e-06);

const scalar pResTol = residualDict.lookupOrDefault<scalar>("pRes", 1e-06);

scalar delta_c1_max = residualDict.lookupOrDefault<scalar>("delta_c1_max", 1e-06);

scalar delta_c2_max = residualDict.lookupOrDefault<scalar>("delta_c2_max", 1e-06);

scalar delta_phiV_max = residualDict.lookupOrDefault<scalar>("delta_phiV_max", 1e-06);

scalar delta_U_max = residualDict.lookupOrDefault<scalar>("delta_U_max", 1e-06);

scalar delta_p_max = residualDict.lookupOrDefault<scalar>("delta_p_max", 1e-06);






 




