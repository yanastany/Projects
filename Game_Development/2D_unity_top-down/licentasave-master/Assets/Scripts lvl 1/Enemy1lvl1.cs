using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using Pathfinding;

public class Enemy1lvl1 : MonoBehaviour
{
    public float distrange;
    public Transform fPoint;
    public GameObject bulletPr;
    public float bulletForce = 20f;
    private Transform player;
    public float firerate = 1;
    private float nfiretime;
    public float Health;
    public float maxHealth = 100;
    [SerializeField] EnemyHealth enHealth;
    public Score score;
    Canvas playerCanvas;
    //public Enemy1Spawner spawner;
    public GameObject _parent;
    // Start is called before the first frame update


    private void Awake()
    {
        player = GameObject.FindGameObjectWithTag("Player").transform;
        enHealth = GetComponentInChildren<EnemyHealth>();
        //spawner = GameObject.FindGameObjectWithTag("Spawner1").GetComponent<Enemy1Spawner>();
        score = GameObject.FindGameObjectWithTag("Canvas").GetComponent<Score>();
        gameObject.GetComponent<AIDestinationSetter>().target = player.transform;
        _parent = gameObject.transform.parent.gameObject;

    }

    void Start()
    {
        player = GameObject.FindGameObjectWithTag("Player").transform;
        enHealth.UpdateHealth(Health, maxHealth);
        //score = playerCanvas.GetComponent<Score>();

    }

    // Update is called once per frame
    void Update()
    {
        float pldistance = Vector2.Distance(player.position, transform.position);
        if (pldistance <= distrange && nfiretime < Time.time)
        {
            GameObject bullet = Instantiate(bulletPr, fPoint.position, fPoint.rotation);
            Rigidbody2D rb = bullet.GetComponent<Rigidbody2D>();
            rb.AddForce(fPoint.up * bulletForce, ForceMode2D.Impulse);
            nfiretime = Time.time + firerate;
        }
        if (Health <= 0)
        {
            score.addPoint(1);
            //Enemy1Spawner.noOfEnemiesAlive--;
            Die();
        }

    }


    private void OnDrawGizmosSelected()
    {
        Gizmos.color = Color.green;
        Gizmos.DrawWireSphere(transform.position, distrange);
    }
    public void TakeDamage(float dmg)
    {
        Health -= dmg;
        enHealth.UpdateHealth(Health, maxHealth);


    }

    public void Die()
    {

        Destroy(gameObject);
        Destroy(_parent);

        //score.addPoint(1);
    }
}
