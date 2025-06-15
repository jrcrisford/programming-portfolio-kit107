/**
 * Interface for Firing Solution
 * ADT specification for KIT107 Assignment 1
 * @author Julian Dermoudy
 * @version 4/3/2024
 * 
 * File is COMPLETE.
 */

public interface FiringSolutionInterface
{
    //public FiringSolution(Time t, int d, double x, double y);
    public void setTime(Time t);
    public Time getTime();
    public void setDegree(int d);
    public int getDegree();
    public void setXValue(double x);
    public double getXValue();
    public void setYValue(double y);
    public double getYValue();
    public String toString();
}