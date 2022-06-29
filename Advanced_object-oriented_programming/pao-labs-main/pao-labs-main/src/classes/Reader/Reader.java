package classes.Reader;

import java.text.SimpleDateFormat;
import java.util.List;
import classes.ItemsClasses.Item;
public class Reader {
    private int age;
    private String name;
    private List<Item> items;
    protected static int count = 0;
    protected int id=0;


    public Reader(){}
    public Reader(int age) {
        this.age = age;
    }

    public Reader(int age, String name, List<Item> items) {
        this.age = age;
        this.name = name;
        this.items = items;
        this.id = count++;
    }
    public Reader(int age, String name) {
        this.age = age;
        this.name = name;
        this.id = count++;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Item> getItems() {
        return items;
    }

    public void setItems(List<Item> items) {
        this.items = items;
    }

    public static int getCount() {
        return count;
    }

    public static void setCount(int count) {
        Reader.count = count;
    }

    public int getId() {
        return id;
    }

    public String toCSV(){
        return age +
                "," + name;
    }


}
