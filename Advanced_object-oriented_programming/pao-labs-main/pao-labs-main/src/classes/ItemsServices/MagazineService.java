package classes.ItemsServices;
import java.util.ArrayList;
import java.util.List;

import classes.ItemsClasses.Book;
import classes.ItemsClasses.Magazine;
public class MagazineService {
    private List<Magazine> magazines = new ArrayList<>();
    private static MagazineService instance;
    private MagazineService(){}
    public static MagazineService getInstance(){
        if(instance == null){
            instance = new MagazineService();
        }
        return instance;
    }

    public List<Magazine> getMagazines() {
        List<Magazine> magazines1 = new ArrayList<>();
        magazines1.addAll(this.magazines);
        return magazines1;
    }

    public Magazine getMagazineById(int id){
        Magazine magazine = new Magazine();
        for(int i=0;i<this.magazines.size();i++){
            if(this.magazines.get(i).getId()==id){
                magazine = this.magazines.get(i);
                break;
            }
        }
        return magazine;
    }

    public void addMagazine(Magazine magazine){
        this.magazines.add(magazine);
    }

    public void updateMagazine(int id, Magazine magazine){
        for(int i = 0; i < this.magazines.size(); ++i){
            if(this.magazines.get(i).getId() == id){
                this.magazines.remove(i);
                this.magazines.add(id, magazine);
                break;
            }
        }
    }

    public void deleteMagazineById(int id){
        for( int i = 0;i<this.magazines.size();i++){
            if(this.magazines.get(i).getId() == id){
                this.magazines.remove(i);
                break;
            }
        }
    }

    public static String toStringMagazine(Magazine a){
        return "The Book's name is " + a.getTitle() +" by " + a.getAuthor().getName() + " and was released in " + a.getRelease_month();
    }

    public static void PrintAllMagazines(List<Magazine> a){
        for( int i = 0;i<a.size();i++)
        {
            System.out.println(toStringMagazine(a.get(i)));
        }

    }


}
