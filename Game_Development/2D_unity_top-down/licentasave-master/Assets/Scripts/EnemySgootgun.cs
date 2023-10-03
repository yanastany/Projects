using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Pathfinding;

public class EnemySgootgun : MonoBehaviour
{
    public float distrange;
    public Transform fPoint;
    public GameObject bulletPr;
    public GameObject bulletRight;
    public GameObject bulletLeft;
    public float bulletForce = 20f;
    private Transform player;
    public float firerate = 1;
    private float nfiretime;
    public float Health;
    public float maxHealth = 100;
    [SerializeField] EnemyHealth enHealth;
    public Score score;
    Canvas playerCanvas;
    public Enemy2Spawner spawner;
    public GameObject _parent;
    public Money coins;
    public GameObject hitef;
    // Start is called before the first frame update


    private void Awake()
    {
        player = GameObject.FindGameObjectWithTag("Player").transform;
        enHealth = GetComponentInChildren<EnemyHealth>();
        spawner = GameObject.FindGameObjectWithTag("Spawner2").GetComponent<Enemy2Spawner>();
        score = GameObject.FindGameObjectWithTag("Canvas").GetComponent<Score>();
        gameObject.GetComponent<AIDestinationSetter>().target = player.transform;
        _parent = gameObject.transform.parent.gameObject;
       coins= GameObject.FindGameObjectWithTag("Canvas").GetComponent<Money>();

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
            GameObject bulletright = Instantiate(bulletRight, fPoint.position, fPoint.rotation);
            Rigidbody2D rbr = bulletright.GetComponent<Rigidbody2D>();
            rbr.AddForce(fPoint.up * bulletForce, ForceMode2D.Impulse);

            GameObject bulletleft = Instantiate(bulletLeft, fPoint.position, fPoint.rotation);
            Rigidbody2D rbl = bulletleft.GetComponent<Rigidbody2D>();
            rbl.AddForce(fPoint.up * bulletForce, ForceMode2D.Impulse);
            nfiretime = Time.time + firerate;
        }
        if (Health <= 0)
        {
            score.addPoint(1);
            coins.addMoney(8);
            Enemy2Spawner.noOfEnemiesAlive--;
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
        GameObject ef = Instantiate(hitef, transform.position, Quaternion.identity);
        Destroy(ef, 0.2f);

        //score.addPoint(1);
    }
}
