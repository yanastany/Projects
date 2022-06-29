package classes.ItemsClasses;

import classes.Author.Author;

import static java.lang.Integer.parseInt;

public class Book extends Item {
    protected Author author;
    protected String release_year;

    public Book() {}

    public Book(int cota, int nrex, String title, Author author, String release_year) {
        super(cota, nrex, title);
        this.author = author;
        this.release_year = release_year;
    }

    public Author getAuthor() {
        return author;
    }

    public void setAuthor(Author author) {
        this.author = author;
    }

    public String getRelease_year() {
        return release_year;
    }
    public int getRelease_yearint() {
        return parseInt(release_year);
    }


    public void setRelease_year(String release_year) {
        this.release_year = release_year;
    }
    public String toCSV(){
        return cota +
                "," + nrex+
                "," + title+
                "," + author.getName()+
                "," + release_year;
    }
}
