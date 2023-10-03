using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletTras : MonoBehaviour
{
    public float TimeToLive = 2f;
    public Shooting s;
    // Start is called before the first frame update
    public GameObject hitef;
    public int dm1;
    public int dm2;
    public int dm3;

    private void Start()
    {
        s = GameObject.FindGameObjectWithTag("Player").
            GetComponent<Shooting>();
        Destroy(gameObject, TimeToLive);
    }

    

    void OnTriggerEnter2D(Collider2D collision)
    {   if(!collision.gameObject.CompareTag("Player") && !gameObject.CompareTag("Bullet"))
        {
            
            Destroy(gameObject);
        }

        if (collision.gameObject.CompareTag("Enemy") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<EnemyShooting>().TakeDamage(s.dmg1);
           
            Destroy(gameObject);
        }
        if (collision.gameObject.CompareTag("Enemy2") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<EnemySgootgun>().TakeDamage(s.dmg2);
            Destroy(gameObject);
        }
        if (collision.gameObject.CompareTag("Enemy3") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<EnemySniper>().TakeDamage(s.dmg3);
            Destroy(gameObject);
        }
        if (collision.gameObject.CompareTag("Enemylvl1") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<Enemy1lvl1>().TakeDamage(s.dmg1);
           
            Destroy(gameObject);
           
        }
        if (collision.gameObject.CompareTag("Enemy2lvl2") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<Enemy2Lvl2>().TakeDamage(s.dmg1);

            Destroy(gameObject);
        }

    }
    
}
