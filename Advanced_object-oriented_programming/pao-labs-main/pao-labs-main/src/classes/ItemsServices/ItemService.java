package classes.ItemsServices;
import java.util.ArrayList;
import java.util.List;
import classes.ItemsClasses.Item;

public class ItemService {
    private List<Item> items = new ArrayList<>();
    private static ItemService instance;
    private ItemService(){}
    public static ItemService getInstance(){
        if(instance == null){
            instance = new ItemService();
        }
        return instance;
    }

    public List<Item> getItems() {
        List<Item> items1 = new ArrayList<>();
        items1.addAll(this.items);
        return items1;
    }

    public Item getItemById(int id){
        Item item = new Item();
        for(int i=0;i<this.items.size();i++){
            if(this.items.get(i).getId()==id){
                item = this.items.get(i);
                break;
            }
        }
        return item;
    }

    public void addItem(Item item){
        this.items.add(item);
    }

    public void updateItem(int id, Item item){
        for(int i = 0; i < this.items.size(); ++i){
            if(this.items.get(i).getId() == id){
                this.items.remove(i);
                this.items.add(id, item);
                break;
            }
        }
    }

    public void deleteItemById(int id){
        for( int i = 0;i<this.items.size();i++){
            if(this.items.get(i).getId() == id){
                this.items.remove(i);
                break;
            }
        }
    }



}

