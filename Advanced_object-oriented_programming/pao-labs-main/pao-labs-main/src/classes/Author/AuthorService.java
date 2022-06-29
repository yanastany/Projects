package classes.Author;

import classes.ItemsClasses.Book;
import classes.Reader.Reader;
import classes.Reader.ReaderService;
import classes.Sorting.SortByDateAuthor;
import classes.Sorting.SortByDateBook;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Objects;

import static java.lang.Integer.parseInt;

public class AuthorService {
    private List<Author> authors = new ArrayList<>();
    private static AuthorService instance;
    public AuthorService(){}
    public static AuthorService getInstance(){
        if(instance == null){
            instance = new AuthorService();
        }
        return instance;
    }

    public List<Author> getAuthors() {
        List<Author> authors1 = new ArrayList<>();
        authors1.addAll(this.authors);
        return authors1;
    }

    public Author getAuthorById(int id){
        Author author = new Author();
        for(int i=0;i<this.authors.size();i++){
            if(this.authors.get(i).getId()==id){
                author = this.authors.get(i);
                break;
            }
        }
        return author;
    }

    public Author getAuthorByName(String name){
        Author author = new Author();
        for(int i=0;i<this.authors.size();i++){
            if(Objects.equals(this.authors.get(i).getName(), name)){
                author = this.authors.get(i);
                break;
            }
        }
        return author;
    }

    public Author getAuthorByPosition(int i){
        Author author = new Author();
        author = this.authors.get(i);
        return author;
    }

    public void addAuthor(Author author){
        this.authors.add(author);
    }

    public void updateAuthor(int id, Author author){
        for(int i = 0; i < this.authors.size(); ++i){
            if(this.authors.get(i).getId() == id){
                this.authors.remove(i);
                this.authors.add(id, author);
                break;
            }
        }
    }

    public void deleteAuthorById(int id){
        for( int i = 0;i<this.authors.size();i++){
            if(this.authors.get(i).getId() == id){
                this.authors.remove(i);
                break;
            }
        }
    }

    public static List<Author> SortByYear(List<Author> a){
        a.sort(new SortByDateAuthor());
        return a;
    }

    public static String toStringAuthor(Author a){
        return "The Author's name is " + a.getName() +", is " + a.getNationality() + " and was born on " + a.getDataString();
    }

    public static void toStringAuthors(List<Author> a){
        for(int i = 0;i<a.size();i++){
            System.out.println(toStringAuthor(a.get(i)));
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
        var columns = AuthorService.getCSV("src/Data/author.csv");
        for(var fields : columns){
            //LocalDate data = LocalDate.parse(fields[2], DateTimeFormatter.ofPattern("dd/MM/yyyy"));
            //SimpleDateFormat d = new SimpleDateFormat(fields[0]);
            SimpleDateFormat outputFormat = new SimpleDateFormat("yyyy/MM/dd");
            Date d = outputFormat.parse(fields[0]);
            var newAuthor = new Author(

                    d,
                    fields[1],
                    fields[2]
            );
            authors.add(newAuthor);
        }
        //CustomerFactory.incrementUniqueId(columns.size());

    }

    public void dumpToCSV(){
        try{
            var r = new FileWriter("src/Data/autor.csv");
            for(var person : this.authors){
                r.write(person.toCSV());
                r.write("\n");
            }
            r.close();
        }catch (IOException e){
            System.out.println(e.toString());
        }
    }

}



