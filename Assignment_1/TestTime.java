

public class TestTime {
    public static void main(String[] args) {
        //Create a Time object representing a specific time
        Time time = new Time(10, 30); //Time is initially set to 10:30:00 AM
        System.out.println("Time is: " + time.toString());

        //Add a certain number of seconds
        double timeToAdd = 60;
        time.addSeconds(timeToAdd);

        //Verify if the time is updated correctly
        System.out.println("Updated Time: " + time.toString()); //Output the updated time
    }
}

