package classes.ItemsServices;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import classes.Author.Author;
import classes.Author.AuthorService;
import classes.ItemsClasses.Book;
import classes.ItemsClasses.CD;

import static java.lang.Integer.parseInt;

public class CDService {
    private List<CD> cDs = new ArrayList<>();
    private static CDService instance;
    private CDService(){}
    public static CDService getInstance(){
        if(instance == null){
            instance = new CDService();
        }
        return instance;
    }

    public List<CD> getCDs() {
        List<CD> cDs1 = new ArrayList<>();
        cDs1.addAll(this.cDs);
        return cDs1;
    }

    public CD getCDById(int id){
        CD cD = new CD();
        for(int i=0;i<this.cDs.size();i++){
            if(this.cDs.get(i).getId()==id){
                cD = this.cDs.get(i);
                break;
            }
        }
        return cD;
    }

    public void addCD(CD cD){
        this.cDs.add(cD);
    }

    public void updateCD(int id, CD cD){
        for(int i = 0; i < this.cDs.size(); ++i){
            if(this.cDs.get(i).getId() == id){
                this.cDs.remove(i);
                this.cDs.add(id, cD);
                break;
            }
        }
    }

    public void deleteCDById(int id){
        for( int i = 0;i<this.cDs.size();i++){
            if(this.cDs.get(i).getId() == id){
                this.cDs.remove(i);
                break;
            }
        }
    }

    public static String toStringCD(CD a){
        return "The CD's name is " + a.getTitle() +" and the type is " + a.getType();
    }

    public static void PrintAllCDs(List<CD> a){
        for( int i = 0;i<a.size();i++)
        {
            System.out.println(toStringCD(a.get(i)));
        }

    }

    private static List<String[]> getCSV(String fileName){

        List<String[]> columns = new ArrayList<>();

        try(var in = new BufferedReader(new FileReader(fileName))) {

            String line;

            while((line = in.readLine()) != null ) {
                //String[] fields = line.replaceAll(" ", "").split(",");
                String[] fields = line.replaceAll("\"", "").split(",");
                columns.add(fields);
            }
        } catch (IOException e) {
            System.out.println("No saved customers!");
        }

        return columns;
    }

    public void loadFromCSV() throws ParseException {
        var columns = CDService.getCSV("src/Data/CD.csv");
        for(var fields : columns){
            var newCD = new CD(

                    parseInt(fields[0]),
                    parseInt(fields[1]),
                    fields[2],
                    fields[3]
            );
            cDs.add(newCD);
        }
        //CustomerFactory.incrementUniqueId(columns.size());

    }

    public void dumpToCSV(){
        try{
            var r = new FileWriter("src/Data/CD.csv");
            for(var person : this.cDs){
                r.write(person.toCSV());
                r.write("\n");
            }
            r.close();
        }catch (IOException e){
            System.out.println(e.toString());
        }
    }


}

