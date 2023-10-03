using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpeedPowerup : MonoBehaviour
{
    // Start is called before the first frame update
    //public GameObject ef;
    public Healthbarscript healthb;
    public SpriteRenderer rnd;
    public Score score;
    public bool resp = false;
    public float oldScore = 0;
    public GameObject player;
    private Canvas canvas;
    public Shooting shooting;
    Collider2D m_Collider;
    public GameObject ef;

    private void Start()
    {
        m_Collider = GameObject.FindGameObjectWithTag("Tile2").GetComponent<Collider2D>();
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.CompareTag("Player"))
        {
           StartCoroutine( Pickup(collision));
        }      
    }

    IEnumerator Pickup(Collider2D collision)
    {
        
        GameObject ef1 =Instantiate(ef, transform.position, transform.rotation);
        Destroy(ef1, 0.3f);
        PlayerMovement h = collision.GetComponent<PlayerMovement>();
        h.moveSpeed = 7;
        rnd.enabled = false;
        gameObject.GetComponent<Collider2D>().enabled = false;
        resp = false;
        yield return new WaitForSeconds(5);
        h.moveSpeed = 5;
    }

    private void Update()
    {
        
        if (score.score % 3 == 0 && score.score > 0 && resp == false && score.score != oldScore)
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

            Vector3 newPos = new Vector3(o[ranX].x-2, o[ranX].y, 0);

            resp = true;
            Transform playerPos = player.GetComponent<Transform>();
         
            gameObject.GetComponent<Collider2D>().enabled = true;
            transform.position = newPos;

            rnd.enabled = true;
            
            oldScore = score.score;

            //if (m_Collider.bounds.Contains(newPos))
            //{
            //    resp = true;
            //    playerPos = player.GetComponent<Transform>();
            //    offset_x = Random.Range(-5f, 5f);
            //    PosX = playerPos.position.x + offset_x;
            //    newPos = new Vector3(PosX, 1, 0);    //the new position for the power-up
            //    gameObject.GetComponent<Collider2D>().enabled = true;
            //    transform.position = newPos;

            //    rnd.enabled = true;

            //    oldScore = score.score;

            //}
        }
        else if (score.score == 0)
        {
            rnd.enabled = false;
            gameObject.GetComponent<Collider2D>().enabled = false;
        }

    }
}
