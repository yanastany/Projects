package classes.ItemsClasses;

import classes.Author.Author;

import java.util.Objects;

public class Magazine extends Item {
    protected String release_month;
    protected Author author;

    public Magazine(){}

    public Magazine(int cota, int nrex, String title, String release_month, Author author) {
        super(cota, nrex, title);
        this.release_month = release_month;
        this.author = author;
    }

    public String getRelease_month() {
        return release_month;
    }

    public void setRelease_month(String release_month) {
        this.release_month = release_month;
    }

    public Author getAuthor() {
        return author;
    }

    public void setAuthor(Author author) {
        this.author = author;
    }
}
