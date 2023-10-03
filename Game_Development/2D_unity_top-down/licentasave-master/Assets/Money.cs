using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class Money : MonoBehaviour
{   public Shooting s;
    public PlayerMovement p;
    public TextMeshProUGUI moneytxt;
    public GameObject snip;
    public GameObject sg;
    public int money = 0;
    public int x1 = 50;
    public TextMeshProUGUI cat_costa;
    public TextMeshProUGUI arma;
    public bool a = false;

    // Start is called before the first frame update
    public void buySniper()
    {
        if (money >= 200)
        {
            s.sniper = true;
            money = money - 200;
            moneytxt.text = money.ToString() + " Coins";
            snip.SetActive(false);
            if (a == true)
            {
                arma.text = "";
            }
            a = true;
        }
    }
    public void buySg()
    {
        if (money >= 50)
        {
            s.sg = true;
            money = money - 50;
            moneytxt.text = money.ToString() + " Coins";
            sg.SetActive(false);
            if (a == true)
            {
                arma.text = "";
            }
            a = true;
        }
    }
    public void addDmg()
    {
        if (money >= x1)
        {
            s.dmgupt(5);
            money = money - x1;
            moneytxt.text = money.ToString() + " Coins";
            x1 = x1 + 5;
            cat_costa.text = "One upgrade costs: " + x1.ToString();
        }
    }
    public void addGloante()
    {
        if (money >= x1)
        {
            s.noOfBulletsPistol = s.noOfBulletsPistol + 20;
            s.noOfBulletssg = s.noOfBulletssg + 30;
            s.noOfBulletssnip = s.noOfBulletssnip + 10;
     
            money = money - x1;
            moneytxt.text = money.ToString() + " Coins";
            x1 = x1 + 5;
            cat_costa.text = "One upgrade costs: " + x1.ToString();
        }
    }

    public void addViata()
    {
        if (money >= x1)
        {
            p.maxHealth = p.maxHealth + 10;
            p.currentHealth = p.maxHealth;
            p.healthb.setHealth(p.currentHealth);

            money = money - x1;
            moneytxt.text = money.ToString() + " Coins";
            x1 = x1 + 5;
            cat_costa.text = "One upgrade costs: " + x1.ToString();
        }
    }




    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.M))
        {
            addMoney(10);
        }
        moneytxt.text = money.ToString() + " Coins";
    }
    public void addMoney(int x)
    {
        money = money + x;
        moneytxt.text = money.ToString() + " Coins";
    }
    public void deleteMoney(int x)
    {
        money = money - x;
        moneytxt.text = money.ToString() + " Coins";
    }
}
