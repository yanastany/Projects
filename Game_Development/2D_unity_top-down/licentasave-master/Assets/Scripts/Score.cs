using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class Score : MonoBehaviour
{
    public TextMeshProUGUI scoretxt;
    public int score = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.M))
        {
            addPoint(1);
        }
        scoretxt.text = score.ToString() + " Coins";
    }
    public void addPoint(int x)
    {
        score = score + x;
        scoretxt.text = score.ToString() + " Coins";
    }
}
