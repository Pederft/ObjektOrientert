# include "canonball.h"
#include "utilities.h"
#include "cannonball_viz.h"


double acclY(){
    double akselerasjon = -9.81;
    return akselerasjon;
}

double velY(double initVelocityY, double time){
    double FartY = initVelocityY + acclY() * time;
    return FartY;
}

double posX(double initPosition, double initVelocity, double time){
    double posisjonX = initPosition + initVelocity * time;
    return posisjonX;
}

double posY(double initPosition, double initVelocity, double time){
    double posisjonY = initPosition + initVelocity * time + (acclY()* (pow(time, 2))/2);
    return posisjonY;
}

void printTime(double sekunder){
    int timer, minutter;
    double sek;
    minutter = sekunder / 60;
    sek = fmod(sekunder , 60);  // Bruker fmod da modulo(%) ikke fungerer på flyttall
    timer = minutter / 60;
    minutter = fmod(minutter , 60);
    cout << "Kanonbllen var:\t" << timer << " timer, " << minutter << " minutter og " << sek << " sekunder i luften!" << endl;
}

double flightTime(double initVelocityY){
    double tid = (-2 * initVelocityY)/acclY();
    return tid;
}


void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    if ((compareOperand - toOperand) <= maxError){
        cout << name << " is valid." << endl;
    } else {
        cout << name << " is not valid, expected: " << toOperand << ", got " << compareOperand << endl;
    }
}


// Ber brukeren om en vinkel
double getUserInputTheta(){
    double vinkel, rad;
    cout << "Vennligst skriv inn en vinkel:\t\t", cin >> vinkel;
    rad = degToRad(vinkel);
    return vinkel;
}



//Ber brukeren om en absoluttfart
double getUserInputAbsVelocity(){
    double absFart;
    cout << "Vennligst skriv inn en absolutt fart:\t", cin >> absFart;
    return absFart;
}



// Konverterer fra grader til radianer
double degToRad(double deg){
    double radianer = deg * (M_PI)/180;
    return radianer;
}


// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel // theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity){
    double FartX = absVelocity * cos(degToRad(theta));
    return FartX;
}


double getVelocityY(double theta, double absVelocity){
    double FartY = absVelocity * sin(degToRad(theta));
    return FartY;
}


// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene // gitt vinkelen theta. Det første elementet i vectoren skal være //x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri 
vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> hastighetsvektor(2);
    hastighetsvektor.at(0) = getVelocityX(theta, absVelocity);
    hastighetsvektor.at(1) = getVelocityY(theta, absVelocity);

    return hastighetsvektor;
}


double getDistanceTraveled(double velocityX, double velocityY){
    double distance_x = velocityX * flightTime(velocityY);
    return distance_x;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){

    double difference = distanceToTarget - getDistanceTraveled(velocityX, velocityY);
    return difference;
}


bool checkIfDistanceToTargetIsCorrect(){
    double error = targetPractice(0,0,0); 
    if(error == 0){
        return true;
    } else{
        return false;
    }
}


void playTargetPractice(){
    int randomSetting;
    randomSetting = randomWithLimits(100, 1000); //Lager først en ny tilfeldig plassering av blinken
    
    for(int i = 0; i<=10; i++){
        cout << "-----------------------------------------------" << endl;
        cout << "Avstand til målet:\t " << randomSetting << "m\n" << endl;
        
        double fart = getUserInputAbsVelocity();     //Brukeren får taste inn sin valgte hastighet
        double vinkel = getUserInputTheta();         //Brukeren får taste inn sin valgte vinkel

        double fartX = getVelocityX(vinkel, fart);
        double fartY = getVelocityY(vinkel, fart);

        double tid = flightTime(fartY);

        double distanse = getDistanceTraveled(fartX, fartY);
        double differanseTilBlink = targetPractice(randomSetting, fartX, fartY);

        printTime(tid);

        cannonBallViz(randomSetting, 1000, fartX, fartY, 100);

        if(differanseTilBlink > 5){
            cout << "\nDu var:\t\t " << differanseTilBlink << "m for kort.\n" <<endl;
        } else if(differanseTilBlink < -5){
            cout << "\nDu var:\t\t " << abs(differanseTilBlink) << "m for langt.\n" <<endl;
        } else{
            cout << "\nDu var innenfor 5 meter.\nDet betyr at du har vunnet!\n" << endl;
            break;
        }


        if (i == 10){
            cout << "\nDu var dessverre ikke nærme nok til å vinne denne gangen, men prøv gjerne igjen!\n" << endl;
        }
    }
}