/**
 * Class for Time
 * ADT implementation for KIT107 Assignment 1
 * @author Julian Dermoudy and Joshua Crisford (574082) and Ewan Walker (448988)
 * @version 24/03/2024
 */

import java.text.DecimalFormat;

public class Time implements TimeInterface
{
    private static final DecimalFormat FMT=new DecimalFormat("00");
    
    private int hour;
    private int minute;
    private int second;
    
    /**
     * Constructor -- midnight
     * @author Julian Dermoudy
     */
    public Time()
    { 
        setTime( 0, 0, 0 ); 
    }
    
    /**
     * Constructor -- to given time
     * @param h new value for hour
     * @param m new value for minute
     * @author Julian Dermoudy
     */
    public Time(int h, int m)
    { 
        setTime( h, m, 0); 
    }
    
    /**
     * Alter hour, minute, and second
     * @param h new value for hour
     * @param m new value for minute
     * @param s new value for second
     * @author Julian Dermoudy
     */
    public void setTime(int h, int m, int s)
    {
        hour = h; 
        minute = m; 
        second = s;
    }
    
    /**
     * Find printable form of time
     * @return String form of time for printing etc.
     * @author Julian Dermoudy
     */
    public String toString()
    { 
        String r;
        
        if (hour >= 12) {
            if (hour == 12)
            {
                r="12";
            }
            else
            {
                r=FMT.format(hour-12);
            }
            r=r+":"+FMT.format(minute)+":"+FMT.format(second)+" PM";
        }
        else {
            if (hour == 0)
            {
                r="12";
            }
            else
            {
                r=FMT.format(hour);
            }
            r=r+":"+FMT.format(minute)+":"+FMT.format(second)+" AM";
        }
        return r;
    }
    
    /**
     * Find printable form of time in 24 hour mode
     * @return String form of time in 24 hour mode for printing etc.
     * @author Julian Dermoudy
     */
    public String toMilitaryString()
    { 
        return FMT.format(hour)+ ":"+FMT.format(minute)+ ":" + FMT.format(second);
    }
    
    /**
     * Determine whether two Time values are equal
     * @param that second Time value
     * @return boolean true if times are equal, false otherwise
     * @author Julian Dermoudy
     */
    public boolean equals(Time that)
    {
        return ((this.hour == that.hour) && (this.minute == that.minute) && (this.second == that.second));
    }
    
    /**
     * Increments time by a specified number of seconds and using that 
     * adjusts the hour, minute and second componants.
     * @param s number of seconds added to time
     * @author Joshua Crisford & Ewan Walker
     */
    public void addSeconds(double s)
    {
        int totalSeconds; //Holds total number of seconds passed
        
        //Calculates total number of second passed
        totalSeconds = (hour * 3600) + (minute * 60) + second;
        
        //Adds the provied number of seconds (s) to the total number of seconds
        totalSeconds += s;

        //Calculate the new time components
        hour = totalSeconds / 3600 % 24;      //Hours from elapsed number of seconds plus (% 24) to handle rolling over to a new day
        minute = (totalSeconds % 3600) / 60;  //Minutes from elapsed number of seconds by coverting to hours then minutes
        second = totalSeconds % 60;           //Seconds from elapsed number of seconds by caluclating the remainder divided by 60
    }
 }
