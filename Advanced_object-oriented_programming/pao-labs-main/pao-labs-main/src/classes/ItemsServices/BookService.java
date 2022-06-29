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
import classes.Sorting.*;

import static java.lang.Integer.parseInt;


public class BookService {
    private List<Book> books = new ArrayList<>();
    private static BookService instance;
    public BookService(){}
    public static BookService getInstance(){
        if(instance == null){
            instance = new BookService();
        }
        return instance;
    }

    public List<Book> getBooks() {
        List<Book> books1 = new ArrayList<>();
        books1.addAll(this.books);
        return books1;
    }

    public Book getBookById(int id){
        Book author = new Book();
        for(int i=0;i<this.books.size();i++){
            if(this.books.get(i).getId()==id){
                author = this.books.get(i);
                break;
            }
        }
        return author;
    }
    public Book getBookByPosition(int i){
        Book author = new Book();
        author = this.books.get(i);
        return author;
    }


    public void addBook(Book author){
        this.books.add(author);
    }

    public void updateBook(int id, Book author){
        for(int i = 0; i < this.books.size(); ++i){
            if(this.books.get(i).getId() == id){
                this.books.remove(i);
                this.books.add(id, author);
                break;
            }
        }
    }

    public void deleteBookById(int id){
        for( int i = 0;i<this.books.size();i++){
            if(this.books.get(i).getId() == id){
                this.books.remove(i);
                break;
            }
        }
    }

    public int numberOfBooks()
    {
        return this.books.size();
    }

    public List<Book> SortByYear(List<Book> a){
      a.sort(new SortByDateBook());
      return a;
    }

    public static String toStringBook(Book a){
        return "The Book's name is " + a.getTitle() +" by " + a.getAuthor().getName() + " and was released in " + a.getRelease_year();
    }

    public static List<Book> BooksByAuthor(Author a, List<Book> b){
        List<Book> books1 = new ArrayList<>();
        for( int i = 0;i<b.size();i++) {
            if (b.get(i).getAuthor() == a) {
                books1.add(b.get(i));


            }
        }return books1;
    }
    public static void PrintAllBooks(List<Book> a){
        for( int i = 0;i<a.size();i++)
        {
            System.out.println(toStringBook(a.get(i)));
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
        var columns = BookService.getCSV("src/Data/book.csv");
        for(var fields : columns){
            Author a =AuthorService.getInstance().getAuthorByName(fields[3]);

            var newBook = new Book(
                    parseInt(fields[0]),
                    parseInt(fields[1]),
                    fields[2],
                    a,
                    fields[4]
            );
            books.add(newBook);
        }
        //CustomerFactory.incrementUniqueId(columns.size());

    }

    public void dumpToCSV(){
        try{
            var r = new FileWriter("src/Data/book.csv");
            for(var person : this.books){
                r.write(person.toCSV());
                r.write("\n");
            }
            r.close();
        }catch (IOException e){
            System.out.println(e.toString());
        }
    }




}
