/**
 * Assignment 1
 * This Java program calculates firing solutions for a missile defense system. It simulates the movement of a missile and a laser, 
 * determining the optimal firing angles based on their positions and charge levels. 
 * @author Joshua Crisford (574082) Ewan Walker (448988)
 * @version 24/03/2024
 */

public class AssigOne124
{
    public static void main(String []args)
    {     
        final double CHARGETIME = 15.757;               //Laser charge time constant
        final double MISSLETIME = 7.405;                //Time for missle to move 1 degree
        final double LASERSPEED = 3.91;                 //Time for laser to move 1 degree
        final double LASERMOVE = MISSLETIME/LASERSPEED; //Laser movement per degree of missle movement
        
        int angle;                      //Angle increment
        double radians;                 //Radian for calculations
        double x;                       //X position in space
        double y;                       //Y position in space
        double laserDegree = 90.0;      //Initial laser angle
        double missleDegree = 0.0;      //Initial missle angle
        double laserCharge = 0.0;       //Laser charge time
        double accumulatedTime = 0.0;   //Accumulated time since missle movement start
        boolean firstHit = false;       //Flag for first hit occurrence

        Time currentTime = new Time(12, 30);                        //Set the inital time
        FiringSolution[] firingSolutions = new FiringSolution[180];     //Array to store firing solutions

        //Iterate through each angle
        for (angle = 0; angle < firingSolutions.length; angle++) 
        {     
            
            //Adjust laser and missle positions base on conditions
            if (firstHit && missleDegree > laserDegree)
            {
                laserDegree += LASERMOVE;   //Increment laser position
            } 
            else if((missleDegree + 1) < (laserDegree - LASERMOVE))
            {
                laserDegree -= LASERMOVE;   //Decrement laser position
            }
                  
            laserCharge += MISSLETIME;      //Updates laser charge timer
                 
            //Calculate firing solutions if conditions met
            if ((missleDegree > laserDegree && firstHit == false) || (missleDegree < laserDegree && firstHit) && (laserCharge >= CHARGETIME))
            {
                //Calculate position based on angle
                radians = Math.toRadians(angle);   
                x = 4000 * Math.cos(radians);       
                y = 20 * Math.sin(radians);         

                //Store and print firing solution
                firingSolutions[angle] = new FiringSolution(currentTime, angle, x, y);
                System.out.println(firingSolutions[angle]);

                //Adjust laser position if first hit hasn't happened
                if(!firstHit)
                {
                    laserDegree += LASERMOVE;
                }
            
            firstHit = true;    //Set first hit flag
            laserCharge = 0.0;  //Reset laser charge
            }
            
            //Update accumulated time
            accumulatedTime += MISSLETIME;

            //Reset time to starting time
            currentTime = new Time(12, 30);  

            //Increment time by missle movement time
            currentTime.addSeconds(accumulatedTime);
            
            //Increment missle angle for next iteration
            missleDegree++;
        } 
    }
}
    
   