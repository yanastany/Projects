using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using System.Threading.Tasks;
using UnityEngine.SceneManagement;
public class Shooting : MonoBehaviour
{
    // Start is called before the first frame update
    public Transform fPoint;
    public Transform backPoint;
    public GameObject bulletPr;
    public GameObject bulletRight;
    public GameObject bulletLeft;
    public GameObject bulletcomRight;
    public GameObject bulletcomLeft;
    public GameObject bulletsniper;
    public float bulletForce = 10f;
    public PlayerMovement playerMovement;
    public float noOfBulletsInRoundPistol;                 //number of bullets in the pistol's round
    public float noOfBulletsPistol;                        //number of bullets left besides the ones in the pistol
    
    [SerializeField] GameObject pistol;
    public TextMeshProUGUI ammoText;
    public int reloadTime = 850;
    public Animator animator;
    private float timer;
    public float firerate;
    public bool sniper = false;
    public bool sg = false;
    public int dmg1 = 10;
    public int dmg2 = 5;
    public int dmg3 = 20;
    public float noOfBulletsInRoundsg;                 
    public float noOfBulletssg;
    public float noOfBulletsInRoundsnip;
    public float noOfBulletssnip;


    private void Start()
    {
        timer += Time.deltaTime;
        noOfBulletsPistol = 100;
        noOfBulletsInRoundPistol = 15;
        noOfBulletssg = 84;
        noOfBulletsInRoundsg = 12;
        noOfBulletsInRoundsnip = 2;              
        noOfBulletssnip = 10;
    // maxNoOfBulletsInRoundPistol = 15;
    ammoText.text = noOfBulletsInRoundPistol.ToString() + "/" + "100";
        animator.SetBool("Shooting", false);
        if (SceneManager.GetActiveScene().buildIndex == 4)
        {
            sg = true;
        }
        if (SceneManager.GetActiveScene().buildIndex == 6)
        {
            sg = true;
            sniper = true;
        }
    }
    // Update is called once per frame
    void Update()
    {
        if (Input.GetButtonDown("Fire1")&& playerMovement.tastatras==0&& noOfBulletsInRoundPistol>0)
        {animator.SetBool("Shooting", true);
            Shoot();
            
        }
        else if (Input.GetKeyDown(KeyCode.R)&& playerMovement.tastatras == 0)
        {
            HandleReloadInput();
        }
        else if (Input.GetKeyDown(KeyCode.R) && playerMovement.tastatras == 1)
        {
            HandleReloadInputsg();
        }
        else if (Input.GetKeyDown(KeyCode.R) && playerMovement.tastatras == 3)
        {
            HandleReloadInputsnip();
        }

        else if (Input.GetButtonDown("Fire1") && playerMovement.tastatras == 1 && noOfBulletsInRoundsg > 2 && sg == true)
        {animator.SetBool("Shooting", true);
            Shoot1();
            
        }
       else if (Input.GetButtonDown("Fire1") && playerMovement.tastatras == 2 && noOfBulletsInRoundsg > 2 && sg ==true)
        {animator.SetBool("Shooting", true);
            Shoot2();
            animator.SetBool("Shooting", true);
        }
       else if (Input.GetButtonDown("Fire1") && playerMovement.tastatras == 3 && noOfBulletsInRoundsnip > 0 && sniper == true)
        {
            Shoot3();
            animator.SetBool("Shooting", true);
        }  
         else
        {
            animator.SetBool("Shooting", false);
        }
      if(playerMovement.tastatras == 0)
        {
            ammoText.text = noOfBulletsInRoundPistol.ToString() + "/" + noOfBulletsPistol.ToString();
        }
        else if(playerMovement.tastatras == 1)
        {
            ammoText.text = noOfBulletsInRoundsg.ToString() + "/" + noOfBulletssg.ToString();
        }
        else if (playerMovement.tastatras == 3)
        {
            ammoText.text = noOfBulletsInRoundsnip.ToString() + "/" + noOfBulletssnip.ToString();
        }
        

    }

    void Shoot()
    {
        GameObject bullet = Instantiate(bulletPr, fPoint.position, fPoint.rotation);
        Rigidbody2D rb = bullet.GetComponent<Rigidbody2D>();
        rb.AddForce(fPoint.up * bulletForce, ForceMode2D.Impulse);
        noOfBulletsInRoundPistol -= 1;
    }

    void Shoot1()
    {
        GameObject bullet = Instantiate(bulletPr, fPoint.position, fPoint.rotation);
        Rigidbody2D rb = bullet.GetComponent<Rigidbody2D>();
        rb.AddForce(Quaternion.Euler(0f,0f,4f)* fPoint.up * bulletForce, ForceMode2D.Impulse);
        GameObject bulletright = Instantiate(bulletRight, fPoint.position, fPoint.rotation);
        Rigidbody2D rbr = bulletright.GetComponent<Rigidbody2D>();
        rbr.AddForce(fPoint.up * bulletForce, ForceMode2D.Impulse);
       
        GameObject bulletleft = Instantiate(bulletLeft, fPoint.position, fPoint.rotation);
        Rigidbody2D rbl = bulletleft.GetComponent<Rigidbody2D>();
        rbl.AddForce(Quaternion.Euler(0f, 0f, -4f) * fPoint.up * bulletForce, ForceMode2D.Impulse);
        noOfBulletsInRoundsg-= 3;
    }
    void Shoot2()
    {
        GameObject bullet = Instantiate(bulletPr, fPoint.position, fPoint.rotation);
        Rigidbody2D rb = bullet.GetComponent<Rigidbody2D>();
        
        
        GameObject bullet1= Instantiate(bulletPr, fPoint.position, fPoint.rotation);
        Rigidbody2D rb1 = bullet1.GetComponent<Rigidbody2D>();
        rb.AddForce(fPoint.up * bulletForce, ForceMode2D.Impulse);
        rb1.AddForce(fPoint.up * bulletForce, ForceMode2D.Impulse);
        noOfBulletsInRoundsg -= 3;

    }
    void Shoot3()
    {
        GameObject bullet = Instantiate(bulletsniper, fPoint.position, fPoint.rotation);
        Rigidbody2D rb = bullet.GetComponent<Rigidbody2D>();
        Debug.Log(fPoint.up);
        rb.AddForce(fPoint.up * bulletForce, ForceMode2D.Impulse);
        noOfBulletsInRoundsnip -= 1;

    }
    public void dmgupt(int x)
    {
        dmg1 = dmg1 + x;
        dmg2 = dmg2 + x;
        dmg3 = dmg3 + x;
    }
    async void HandleReloadInput()
    {
        if (noOfBulletsPistol > 0 )
        {
                  

            await Task.Delay((int)(reloadTime * 1 / Time.timeScale));     //add delay of 1.5s to reload task

           
           
            if(noOfBulletsInRoundPistol == 0 && noOfBulletsPistol>15)
            {
                noOfBulletsInRoundPistol = 15;
                noOfBulletsPistol -= 15;
            }
            if(noOfBulletsInRoundPistol == 0 && noOfBulletsPistol <= 15)
            {
                noOfBulletsInRoundPistol = noOfBulletsPistol;
                noOfBulletsPistol = 0;

            }
            if (noOfBulletsInRoundPistol > 0 && noOfBulletsPistol -15+ noOfBulletsInRoundPistol >= 0)
            {
                noOfBulletsPistol =noOfBulletsPistol-15+ noOfBulletsInRoundPistol;
                noOfBulletsInRoundPistol = 15;
                
            }
            if (noOfBulletsInRoundPistol > 0 && noOfBulletsPistol - 15 + noOfBulletsInRoundPistol < 0)
            {   
                noOfBulletsInRoundPistol = noOfBulletsInRoundPistol+noOfBulletsPistol;
                noOfBulletsPistol = 0;
             
            }
        }
    }

    async void HandleReloadInputsg()
    {
        if (noOfBulletssg > 0)
        {


            await Task.Delay((int)(reloadTime * 1 / Time.timeScale));     



            if (noOfBulletsInRoundsg == 0 && noOfBulletssg > 12)
            {
                noOfBulletsInRoundsg = 12;
                noOfBulletssg -= 12;
            }
            if (noOfBulletsInRoundsg == 0 && noOfBulletssg <= 12)
            {
                noOfBulletsInRoundsg = noOfBulletssg;
                noOfBulletssg = 0;

            }
            if (noOfBulletsInRoundsg > 0 && noOfBulletssg - 12 + noOfBulletsInRoundsg >= 0)
            {
                noOfBulletssg = noOfBulletssg - 12 + noOfBulletsInRoundsg;
                noOfBulletsInRoundsg = 12;

            }
            if (noOfBulletsInRoundsg > 0 && noOfBulletssg - 12 + noOfBulletsInRoundsg < 0)
            {
                noOfBulletsInRoundsg = noOfBulletsInRoundsg + noOfBulletssg;
                noOfBulletssg = 0;

            }
        }
    }

    async void HandleReloadInputsnip()
    {
        if (noOfBulletssnip > 0)
        {


            await Task.Delay((int)(reloadTime * 1 / Time.timeScale));



            if (noOfBulletsInRoundsnip == 0 && noOfBulletssnip > 2)
            {
                noOfBulletsInRoundsnip = 2;
                noOfBulletssnip -= 2;
            }
            if (noOfBulletsInRoundsnip == 0 && noOfBulletssnip <= 2)
            {
                noOfBulletsInRoundsnip = noOfBulletssnip;
                noOfBulletssnip = 0;

            }
            if (noOfBulletsInRoundsnip > 0 && noOfBulletssnip - 2 + noOfBulletsInRoundsnip >= 0)
            {
                noOfBulletssnip = noOfBulletssnip - 2 + noOfBulletsInRoundsnip;
                noOfBulletsInRoundsnip = 2;

            }
            if (noOfBulletsInRoundsnip > 0 && noOfBulletssnip - 2 + noOfBulletsInRoundsnip < 0)
            {
                noOfBulletsInRoundsnip = noOfBulletsInRoundsnip + noOfBulletssnip;
                noOfBulletssnip = 0;

            }
        }
    }

}
