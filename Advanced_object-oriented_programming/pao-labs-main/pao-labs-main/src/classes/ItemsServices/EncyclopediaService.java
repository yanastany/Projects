package classes.ItemsServices;
import java.util.ArrayList;
import java.util.List;

import classes.ItemsClasses.Book;
import classes.ItemsClasses.Encyclopedia;

public class EncyclopediaService {
    private List<Encyclopedia> encyclopedias = new ArrayList<>();
    private static EncyclopediaService instance;
    private EncyclopediaService(){}
    public static EncyclopediaService getInstance(){
        if(instance == null){
            instance = new EncyclopediaService();
        }
        return instance;
    }

    public List<Encyclopedia> getEncyclopedias() {
        List<Encyclopedia> encyclopedias1 = new ArrayList<>();
        encyclopedias1.addAll(this.encyclopedias);
        return encyclopedias1;
    }

    public Encyclopedia getEncyclopediaById(int id){
        Encyclopedia encyclopedia = new Encyclopedia();
        for(int i=0;i<this.encyclopedias.size();i++){
            if(this.encyclopedias.get(i).getId()==id){
                encyclopedia = this.encyclopedias.get(i);
                break;
            }
        }
        return encyclopedia;
    }

    public void addEncyclopedia(Encyclopedia encyclopedia){
        this.encyclopedias.add(encyclopedia);
    }

    public void updateEncyclopedia(int id, Encyclopedia encyclopedia){
        for(int i = 0; i < this.encyclopedias.size(); ++i){
            if(this.encyclopedias.get(i).getId() == id){
                this.encyclopedias.remove(i);
                this.encyclopedias.add(id, encyclopedia);
                break;
            }
        }
    }

    public void deleteEncyclopediaById(int id){
        for( int i = 0;i<this.encyclopedias.size();i++){
            if(this.encyclopedias.get(i).getId() == id){
                this.encyclopedias.remove(i);
                break;
            }
        }
    }

    public static String toStringEnc(Encyclopedia a){
        return "The Encyclopedia's name is " + a.getTitle() +" by " + a.getAuthor().getName() + " and the type is " + a.getType();
    }
    public static void PrintAllEnc(List<Encyclopedia> a){
        for( int i = 0;i<a.size();i++)
        {
            System.out.println(toStringEnc(a.get(i)));
        }

    }


}
