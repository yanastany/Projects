using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
public class PlayerMovement : MonoBehaviour
{



    // Start is called before the first frame update
    public float moveSpeed = 5f;
    public Rigidbody2D rb;
    Vector2 movement;
    Vector2 mPoz;
    public Camera cam;
    public int tastatras=0;
    public int maxHealth = 100;
    public int currentHealth;
    public Healthbarscript healthb;
    public bool Alive = true;
    public Animator animator;
    public RawImage pistol;
    public RawImage shootgun;
    public RawImage sniper;
    public Score Score;
    


    void Start()
    {
        currentHealth = maxHealth;
        healthb.SetMaxH(maxHealth);
        Score = GameObject.FindGameObjectWithTag("Canvas").GetComponent<Score>();
        Time.timeScale = 1f;

    }

    // Update is called once per frame
    void Update()
    {
        movement.x = Input.GetAxisRaw("Horizontal");
        movement.y = Input.GetAxisRaw("Vertical");
        if(Mathf.Abs(movement.x)> Mathf.Abs(movement.y))
        { animator.SetFloat("Speed",Mathf.Abs( movement.x));}
        else
        {
            animator.SetFloat("Speed", Mathf.Abs(movement.y));
        }
        
        mPoz = cam.ScreenToWorldPoint(Input.mousePosition);

        if (Input.GetKeyDown(KeyCode.Space))
        {
            TakeDamage(20);
        }
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            tastatras = 0;
            pistol.enabled = true;
            shootgun.enabled = false;
            sniper.enabled = false;
        }

        if (Input.GetKeyDown(KeyCode.Alpha2))
        {
            tastatras = 1;
            pistol.enabled = false;
            shootgun.enabled = true;
            sniper.enabled = false;
        }
        if (Input.GetKeyDown(KeyCode.Alpha3))
        {
            tastatras = 3;
            pistol.enabled = false;
            shootgun.enabled = false;
            sniper.enabled = true;
        }

        
        

    }


    private void FixedUpdate()
    {
        rb.MovePosition(rb.position + movement * moveSpeed * Time.fixedDeltaTime);
        Vector2 lookDir = mPoz - rb.position;
        float ang = Mathf.Atan2(lookDir.y, lookDir.x) * Mathf.Rad2Deg - 90f;
        rb.rotation = ang;
    }

    public void TakeDamage(int damage)
    {
        currentHealth -= damage;
        healthb.setHealth(currentHealth);
    }

    public bool isAlive()
    {
        return Alive;
    }


    //void OnCollisionEnter2D(Collision2D collision)
    //{

    //    if (collision.gameObject.tag == "EnemyBullet")
    //    {
    //        TakeDamage(10);
    //        Destroy(collision.gameObject);
    //    }
    //}



}
