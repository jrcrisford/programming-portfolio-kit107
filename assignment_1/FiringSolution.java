/**
 * Class for Firing Solution
 * ADT Implmentation for KIT107 Assignment 1
 * @author Julian Dermoudy and Joshua Crisford (574082) and Ewan Walker (448988)
 * @version 24/03/2024
 */

import java.text.DecimalFormat;

public class FiringSolution implements FiringSolutionInterface
{
    private static final DecimalFormat FMT = new DecimalFormat("###0.000");
    
    private Time time;      //Hold time
    private int degree;     //Holds the angle
    private double x;       //Holds the x position
    private double y;       //Holds the y position
    
    /**
     * Constructor for the firing solution
     * @param time
     * @param degree
     * @param x
     * @param y
     * @author Joshua Crisford & Ewan Walker
     */
    public FiringSolution(Time time, int degree, double x, double y)
    {      
        this.time = time;
        this.degree = degree;
        this.x = x;
        this.y = y;
    }
    
    /**
     * Set the firing time
     * @param t the firing time
     * @author Joshua Crisford & Ewan Walker
     */
    public void setTime(Time t) 
    {
        this.time = t;
    }

    /**
     * Get the firing time
     * @return the firing time
     * @author Joshua Crisford & Ewan Walker
     */
    public Time getTime()
    {
        return time;
    }

    /**
     * Set the firing angle
     * @param d the firing angle
     * @author Joshua Crisford & Ewan Walker
     */
    public void setDegree(int d)
    {
        this.degree = d;
    }

    /**
     * Get the firing angle
     * @return the firing angle
     * @author Joshua Crisford & Ewan Walker
     */
    public int getDegree()
    {
        return degree;
    }

    /**
     * Set the x-coordinate of the target
     * @param x the x-coordinate
     * @author
     */
    public void setXValue(double x)
    {
        this.x = x;
    }

    /**
     * Get the x-coordinate of the target
     * @return the x-coordinate
     * @author Joshua Crisford & Ewan Walker
     */
    public double getXValue() 
    {
        return x;
    }

    /**
     * Set the y-coordinate of the target
     * @param y the y-coordinate
     * @author Joshua Crisford & Ewan Walker
     */
    public void setYValue(double y)
    {
        this.y = y;
    }

    /**
     * Get the y-coordinate of the target
     * @return the x-coordinate
     * @author Joshua Crisford & Ewan Walker
     */
    public double getYValue()
    {
        return y;
    }

    /**
     * Create a string representation of the firing solution
     * @return the string representation
     * @author Joshua Crisford & Ewan Walker
     */
    public String toString() 
    {
        String timeStr = getTime().toString();              //Holds time as a string
        String degreeStr = Integer.toString(getDegree());   //Holds degree as a string
        String xStr = FMT.format(getXValue());              //Holds x value as a string
        String yStr = FMT.format(getYValue());              //Holds y value as a string

        //Provide correct formatting for output
        return "At time " + timeStr + ", fire at " + degreeStr + " degrees to impact missile at (" + xStr + ", " + yStr + ")";
    }
 }