package classes.Reader;

import classes.ItemsClasses.Book;
import classes.ItemsClasses.Manga;
import classes.Sorting.SortByAgeReader;
import classes.Sorting.SortByDateBook;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Integer.parseInt;

public class ReaderService {
    private List<Reader> readers = new ArrayList<>();
    private static ReaderService instance;
    private ReaderService(){}
    public static ReaderService getInstance(){
        if(instance == null){
            instance = new ReaderService();
        }
        return instance;
    }

    public List<Reader> getReaders() {
        List<Reader> readers1 = new ArrayList<>();
        readers1.addAll(this.readers);
        return readers1;
    }

    public Reader getReaderById(int id){
        Reader reader = new Reader();
        for(int i=0;i<this.readers.size();i++){
            if(this.readers.get(i).getId()==id){
                reader = this.readers.get(i);
                break;
            }
        }
        return reader;
    }

    public void addReader(Reader reader){
        this.readers.add(reader);
    }

    public void updateReader(int id, Reader reader){
        for(int i = 0; i < this.readers.size(); ++i){
            if(this.readers.get(i).getId() == id){
                this.readers.remove(i);
                this.readers.add(id, reader);
                break;
            }
        }
    }

    public void deleteReaderById(int id){
        for( int i = 0;i<this.readers.size();i++){
            if(this.readers.get(i).getId() == id){
                this.readers.remove(i);
                break;
            }
        }
    }


    public List<Reader> SortByAge(List<Reader> a){
        a.sort(new SortByAgeReader());
        return a;
    }

    public static String toStringReader(Reader a){
        return "The reader's name is " + a.getName() +" and is " + a.getAge();
    }

    public static void PrintAllReaders(List<Reader> a){
        for( int i = 0;i<a.size();i++)
        {
            System.out.println(toStringReader(a.get(i)));
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

    public void loadFromCSV() {
        var columns = ReaderService.getCSV("src/Data/reader.csv");
        for(var fields : columns){
            var newReader = new Reader(
                    parseInt(fields[0]),
                    fields[1]
            );
            readers.add(newReader);
        }
        //CustomerFactory.incrementUniqueId(columns.size());

    }

    public void dumpToCSV(){
        try{
            var r = new FileWriter("src/Data/reader.csv");
            for(var person : this.readers){
                r.write(person.toCSV());
                r.write("\n");
            }
            r.close();
        }catch (IOException e){
            System.out.println(e.toString());
        }
    }


}
