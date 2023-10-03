using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class spdpow : MonoBehaviour
{
    // Start is called before the first frame update
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
            StartCoroutine(Pickup(collision));
        }
    }

    IEnumerator Pickup(Collider2D collision)
    {

        GameObject ef1 = Instantiate(ef, transform.position, transform.rotation);
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

        if (score.score % 5 == 0 && score.score > 0 && resp == false && score.score != oldScore)
        {

            

            resp = true;
            Transform playerPos = player.GetComponent<Transform>();

            gameObject.GetComponent<Collider2D>().enabled = true;
            

            rnd.enabled = true;

            oldScore = score.score;

         
        }
        else if (score.score == 0)
        {
            rnd.enabled = false;
            gameObject.GetComponent<Collider2D>().enabled = false;
        }

    }
}
