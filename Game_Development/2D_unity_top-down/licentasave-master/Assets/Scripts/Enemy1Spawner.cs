using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy1Spawner : MonoBehaviour
{
    [SerializeField] GameObject Enemy1Prefab;

    Transform player;

    public static Enemy1Spawner Instance;

    public static int noOfEnemiesAlive = 0;

    GameObject _parent;
    public PlayerMovement play;

    void Awake()
    {
        Instance = GetComponent<Enemy1Spawner>();
        player = GameObject.FindGameObjectWithTag("Player").GetComponent<Transform>();
    }
    void Start()
    {
        noOfEnemiesAlive = 0;
        _parent = GameObject.Find("Enm");
        StartCoroutine(Spawn());
    }

    IEnumerator Spawn()
    {
        if (noOfEnemiesAlive < 3)
        {
            List<Vector2> o = new List<Vector2>();
            Vector2 z;
            z.x = -7;
            z.y = -2;
            o.Add(z);
            z.x = -5;
            z.y = -7;
            o.Add(z);
            z.x = 3;
            z.y = 8;
            o.Add(z);
            z.x = 3;
            z.y = -3;
            o.Add(z);
            z.x = 22;
            z.y = -3;
            o.Add(z);
            z.x = 22;
            z.y = 6;
            o.Add(z);
            z.x = 12;
            z.y = 8;
            o.Add(z);
            z.x = 12;
            z.y = -3;
            o.Add(z);

            int ranX = Random.Range(0, 8);                          
            Vector3 spawnPosition = new Vector3(o[ranX].x, o[ranX].y, 0);
            Debug.Log(o[ranX].x);
            Debug.Log(o[ranX].y);
            GameObject enemy = Instantiate(Enemy1Prefab, spawnPosition, Quaternion.identity);
            enemy.tag = "Enemy";
            noOfEnemiesAlive++;
        }
        yield return new WaitForSeconds(7);
        if (play.isAlive())
        {
            StartCoroutine(Spawn());
        }
    }
}
