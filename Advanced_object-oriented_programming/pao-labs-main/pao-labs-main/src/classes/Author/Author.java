package classes.Author;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Author {
    private Date date_of_birth;
    private String nationality;
    protected String name;
    protected static int count = 0;
    protected int id=0;

    public Author(){}

    public Author(Date date_of_birth) {
        this.date_of_birth = date_of_birth;
    }

    public Author(Date date_of_birth,String nationality,String name){
        this(date_of_birth);
        this.nationality = nationality;
        this.name = name;
        this.id = count++;

    }

    public void setDate_of_birth(Date date_of_birth) {
        this.date_of_birth = date_of_birth;
    }

    public void setNationality(String nationality) {
        this.nationality = nationality;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Date getDate_of_birth() {
        return date_of_birth;
    }
    public String getDataString()
    {
        SimpleDateFormat DateFor = new SimpleDateFormat("yyyy");
        return DateFor.format(date_of_birth);
    }


    public String getNationality() {
        return nationality;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }
    public String toCSV(){
        return date_of_birth +
                "," + nationality + "," + name;
    }


}
