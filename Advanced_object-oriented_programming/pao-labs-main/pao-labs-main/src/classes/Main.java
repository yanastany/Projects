package classes;
import classes.Audit.AuditService;
import classes.Author.*;
import classes.Generice.citire;

import classes.Generice.scriere;
import classes.ItemsClasses.*;
import classes.ItemsServices.*;
import classes.Reader.Reader;
import classes.Reader.ReaderService;


import java.io.IOException;
import java.text.ParseException;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

import static java.lang.Integer.parseInt;

public class Main {

    public static void main(String[] args) throws ParseException, IOException {

   /* Author a1 = new Author(new Date(-52, Calendar.JANUARY,18),"Romanian","Ioan Slavici" );
    System.out.println(a1.getDataString());
    System.out.println(a1.getNationality());

    Book b1 = new Book(100, 100, "Mara", a1, "1894");
    Book b2 = new Book(100, 100, "Moara cu Noroc", a1, "1881");
        //System.out.println(b2.getId());
    BookService books = new BookService();
    books.addBook(b1);
    books.addBook(b2);
    System.out.println(AuthorService.toStringAuthor(a1));
    List<Book> bks1 = new ArrayList<>();
    bks1= books.SortByYear(books.getBooks());
    for(int i = 0;i< bks1.size();i++){
        System.out.println(bks1.get(i).getRelease_year());
        ;
    }*/

        //Author
//        Author a1 = new Author(new Date(-52, Calendar.JANUARY,18),"Romanian","Ioan Slavici" );
//        Author a2 = new Author(new Date(60,Calendar.JUNE,7),"Japanese","Hirohiko Araki");
//        Author a3 = new Author(new Date(69, Calendar.AUGUST,4),"British","Jojo Moyes" );
//        Author a4 = new Author(new Date(86,Calendar.AUGUST,29),"Japanese","Hajime Isayama");
//        AuthorService auts1 = new AuthorService();
//        List<Author> auts = new ArrayList<>();
//        auts1.addAuthor(a1);
//        auts1.addAuthor(a2);
//        auts1.addAuthor(a4);
//        auts1.addAuthor(a3);
//        auts = AuthorService.SortByYear(auts1.getAuthors());
//        AuthorService.toStringAuthors(auts);
//        //Book
//        Book b1 = new Book(80, 2, "Still Me", a3, "2018");
//        Book b2 = new Book(100, 15, "Moara cu Noroc", a1, "1881");
//        Book b3 = new Book(98, 3, "After you", a3, "2015");
//        Book b4 = new Book(99, 5, "Me Before You", a3, "2012");
//        Book b5 = new Book(101, 10, "Mara", a1, "1894");
//
//
//
//        BookService books = new BookService();
//        books.addBook(b1);
//        books.addBook(b2);
//        books.addBook(b3);
//        books.addBook(b4);
//        books.addBook(b5);
//        List<Book> bks1 = new ArrayList<>();
//        //sortam dupa an
//        bks1= books.SortByYear(books.getBooks());
//        //le afisam pe toate
//        System.out.println("Cartile sortate dupa an:\n");
//        BookService.PrintAllBooks(bks1);
//        System.out.println("Cartile scrise de autorul a3:\n");
//        //afisam cartile scrise de autorul a3
//        BookService.PrintAllBooks(BookService.BooksByAuthor(a3,bks1));
//        System.out.println("\n");
//        //Manga
//        Manga m1 = new Manga(30,2,"JoJo's Bizarre Adventure: Golden Wind",a2,1);
//        Manga m2 = new Manga(20,6,"JoJo's Bizarre Adventure: Golden Wind",a2,2);
//        Manga m3 = new Manga(43,10,"JoJo's Bizarre Adventure: Stardust Crusaders",a2,5);
//        MangaService mangas = new MangaService();
//        mangas.addManga(m1);
//        mangas.addManga(m2);
//        mangas.addManga(m3);
//        List<Manga> mngs1 = new ArrayList<>();
//        mngs1 = mangas.AllChaptersFromaMangaSeries(m1);
//        MangaService.PrintAllMangas(mngs1);
        AuditService audit = new AuditService();


        ReaderService personService = ReaderService.getInstance();
        personService.loadFromCSV();
        List<Reader> r = new ArrayList<>();
        r = ReaderService.getInstance().getReaders();
        ReaderService.PrintAllReaders(r);
        audit.actiuneaudit("New readers");
//        for(var i:r)
//            System.out.println(i);

        AuthorService authorService = AuthorService.getInstance();
        authorService.loadFromCSV();
        List<Author> a = new ArrayList<>();
        a = AuthorService.getInstance().getAuthors();
        AuthorService.toStringAuthors(a);

        audit.actiuneaudit("New authors");

        BookService bookService = BookService.getInstance();
        bookService.loadFromCSV();
        List<Book> b = new ArrayList<>();
        b = BookService.getInstance().getBooks();
        BookService.PrintAllBooks(b);
        audit.actiuneaudit("New books");

        CDService cdService = CDService.getInstance();
        cdService.loadFromCSV();
        List<CD> c = new ArrayList<>();
        c = CDService.getInstance().getCDs();
        CDService.PrintAllCDs(c);
        audit.actiuneaudit("New CDs");

        MangaService mangaService = MangaService.getInstance();
        mangaService.loadFromCSV();
        mangaService.dumpToCSV();
        List<Manga> m = new ArrayList<>();
        m = MangaService.getInstance().getMangas();
        MangaService.PrintAllMangas(m);
        audit.actiuneaudit("New Mangas");

        try {
            List<Reader> readers = citire.getInstance().read("src/Data/reader.csv",Reader.class);
            ReaderService.PrintAllReaders(readers);
            audit.actiuneaudit("New readers");
            readers.get(0).setAge(22);
            scriere.getInstance().write(readers,"src/Data/reader1.csv");
            audit.actiuneaudit("New writing in readers1");

        } catch (Exception e) {
            e.printStackTrace();
        }

        usingStreams(b);



    }



    private static void usingStreams(List<Book> books) {
        books.stream()
                .filter(book -> isOlderThanTwoThousand(book))

                .sorted(Comparator.comparing(Book::getRelease_yearint))
                .map(book -> book.getTitle())
                .forEach(System.out::println);
    }



    private static boolean isOlderThanTwoThousand(Book book) {
        return parseInt(book.getRelease_year()) < 2000;
    }

}
