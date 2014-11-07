/* --------------- Reading physical properties -------------- */
    
    Info<< "Reading physicalProperties\n" << endl;
    IOdictionary physicalProperties
    (
        IOobject
        (
            "physicalProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

    dimensionedScalar epsilon0
    (
        physicalProperties.lookup("epsilon0")
    );

    dimensionedScalar epsilonr
    (
        physicalProperties.lookup("epsilonr")
    );

    dimensionedScalar z1
    (
        physicalProperties.lookup("z1")
    );	

    dimensionedScalar z2				
    (
        physicalProperties.lookup("z2")
    );

    dimensionedScalar D1				
    (
        physicalProperties.lookup("D1")
    );

    dimensionedScalar D2
    (
        physicalProperties.lookup("D2")
    );
    
    dimensionedScalar kBT
    (
        physicalProperties.lookup("kBT")
    );

    dimensionedScalar NA
    (
        physicalProperties.lookup("NA")
    );

    dimensionedScalar eCharge
    (
	physicalProperties.lookup("eCharge")
    );

    dimensionedScalar nu
    (
        physicalProperties.lookup("nu")
    );

    dimensionedScalar rho
    (
        physicalProperties.lookup("rho")
    );

/* ------------------ creating fields --------------------*/

    Info<< "Reading field phiV\n" << endl;
    volScalarField phiV
    (
        IOobject
        (
            "phiV",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field c1\n" << endl;
    volScalarField c1
    (
        IOobject
        (
            "c1",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field c2\n" << endl;
    volScalarField c2
    (
        IOobject
        (
            "c2",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field p\n" << endl;
    volScalarField p
    (
        IOobject
        (
            "p",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field U\n" << endl;
    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    volVectorField E
    (
        IOobject
        (
            "E",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        -fvc::grad(phiV)
    );

    #include "createPhi.H"

/* ---------------------- setting reference pressure and cell ---------------------*/

    label pRefCell = 0;
    scalar pRefValue = 0.0;
    setRefCell(p, mesh.solutionDict().subDict("nppStokesSteadyControl"), pRefCell, pRefValue);
