using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AmmoPowerup : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject ef;
    public Healthbarscript healthb;
    public SpriteRenderer rnd;
    public Score score;
    public bool resp = false;
    public float oldScore = 0;
    public GameObject player;
    private Canvas canvas;
    public Shooting shooting;
    Collider2D m_Collider;


    private void Start()
    {
        m_Collider = GameObject.FindGameObjectWithTag("Tile2").GetComponent<Collider2D>();
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log(collision.tag);
        if (collision.CompareTag("Player"))
        {
            Pickup(collision);
        }
       
    }

    void Pickup(Collider2D collision)
    {
        GameObject ef1 = Instantiate(ef, transform.position, transform.rotation);
        Destroy(ef1, 0.3f);
        Shooting h = collision.GetComponent<Shooting>();
        h.noOfBulletsPistol=h.noOfBulletsPistol+20;
        h.noOfBulletssg = h.noOfBulletssg + 30;
        h.noOfBulletssnip = h.noOfBulletssnip + 10;
        rnd.enabled = false;
        gameObject.GetComponent<Collider2D>().enabled = false;
        resp = false;
    }

    private void Update()
    {

        if (score.score % 5 == 0 && score.score > 0 && resp == false && score.score != oldScore)
        {

            List<Vector2> o = new List<Vector2>();
            Vector2 z;
            z.x = 16;
            z.y = 6;
            o.Add(z);
            z.x = 15;
            z.y = -5;
            o.Add(z);
            z.x = -9;
            z.y = -6;
            o.Add(z);

            int ranX = Random.Range(0, 3);
            Vector3 newPos = new Vector3(o[ranX].x-1, o[ranX].y, 0);
            resp = true;
            Transform playerPos = player.GetComponent<Transform>();
           
            gameObject.GetComponent<Collider2D>().enabled = true;
            transform.position = newPos;

            rnd.enabled = true;

            oldScore = score.score;

            //if (m_Collider.bounds.Contains(newPos))
            //{
            //resp = true;
            //playerPos = player.GetComponent<Transform>();
            //offset_x = Random.Range(-5f, 5f);
            // PosX = playerPos.position.x + offset_x;
            //newPos = new Vector3(PosX, 1, 0);    //the new position for the power-up
            //gameObject.GetComponent<Collider2D>().enabled = true;
            //transform.position = newPos;
            
            //rnd.enabled = true;
            
            //oldScore = score.score;
                
            //}
            
        }
        else if (score.score == 0)
        {
            rnd.enabled = false;
            gameObject.GetComponent<Collider2D>().enabled = false;
        }

    }
}
