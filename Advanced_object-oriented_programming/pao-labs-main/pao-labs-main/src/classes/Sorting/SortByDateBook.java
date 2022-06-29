package classes.Sorting;

import classes.Author.Author;
import classes.ItemsClasses.Book;

import java.util.Comparator;

public class SortByDateBook implements Comparator<Book> {
    @Override
    public int compare(Book a, Book b)
    {
        return Integer.parseInt(a.getRelease_year()) - Integer.parseInt(b.getRelease_year());
    }
}

