package classes.ItemsServices;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;

import classes.Author.Author;
import classes.Author.AuthorService;
import classes.ItemsClasses.Book;
import classes.ItemsClasses.Manga;

import static java.lang.Integer.parseInt;

public class MangaService {
    private List<Manga> mangas = new ArrayList<>();
    private static MangaService instance;

    public MangaService() {
    }

    public static MangaService getInstance() {
        if (instance == null) {
            instance = new MangaService();
        }
        return instance;
    }

    public List<Manga> getMangas() {
        List<Manga> mangas1 = new ArrayList<>();
        mangas1.addAll(this.mangas);
        return mangas1;
    }

    public Manga getMangaById(int id) {
        Manga manga = new Manga();
        for (int i = 0; i < this.mangas.size(); i++) {
            if (this.mangas.get(i).getId() == id) {
                manga = this.mangas.get(i);
                break;
            }
        }
        return manga;
    }

    public void addManga(Manga manga) {
        this.mangas.add(manga);
    }

    public void updateManga(int id, Manga manga) {
        for (int i = 0; i < this.mangas.size(); ++i) {
            if (this.mangas.get(i).getId() == id) {
                this.mangas.remove(i);
                this.mangas.add(id, manga);
                break;
            }
        }
    }

    public void deleteMangaById(int id) {
        for (int i = 0; i < this.mangas.size(); i++) {
            if (this.mangas.get(i).getId() == id) {
                this.mangas.remove(i);
                break;
            }
        }
    }

    public static String toStringManga(Manga a) {
        return "The Book's name is " + a.getTitle() + " by " + a.getAuthor().getName() + " and the number of the chapter is " + a.getChapter();
    }

    public static void PrintAllMangas(List<Manga> a) {
        for (int i = 0; i < a.size(); i++) {
            System.out.println(toStringManga(a.get(i)));
        }

    }

    public List<Manga> AllChaptersFromaMangaSeries(Manga a) {
        List<Manga> mangas1 = new ArrayList<>();
        for (int i = 0; i < this.mangas.size(); i++) {
            if (a.getTitle()==this.mangas.get(i).getTitle())
                mangas1.add(this.mangas.get(i));
        }
        return mangas1;
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
        var columns = MangaService.getCSV("src/Data/manga.csv");
        for(var fields : columns){
            Author a = AuthorService.getInstance().getAuthorByName(fields[3]);

            var newManga = new Manga(
                    parseInt(fields[0]),
                    parseInt(fields[1]),
                    fields[2],
                    a,
                    parseInt(fields[4])
            );
            mangas.add(newManga);
        }
        //CustomerFactory.incrementUniqueId(columns.size());

    }

    public void dumpToCSV(){
        try{
            var r = new FileWriter("src/Data/manga.csv");
            for(var person : this.mangas){
                r.write(person.toCSV());
                r.write("\n");
            }
            r.close();
        }catch (IOException e){
            System.out.println(e.toString());
        }
    }


}
