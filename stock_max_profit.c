#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

/* Problem statemet:
 * Stock Buy and Sell to maximize profit.
 */

typedef struct
{
	int bIdx;
	int sIdx;
	int maxProfit;
}profitDetails_t;

void maxProfit(int *prices, size_t n, profitDetails_t *res)
{
	int minStockPrice = INT_MAX;
	int stock_idx;

	res->maxProfit = 0;

	for(stock_idx=0; stock_idx<n; stock_idx++)
	{
		if(prices[stock_idx] < minStockPrice) {
			minStockPrice = prices[stock_idx];
			res->bIdx = stock_idx;
		} else if ((prices[stock_idx] - minStockPrice) > res->maxProfit) {
			res->maxProfit = prices[stock_idx] - minStockPrice;
			res->sIdx      = stock_idx;
		}
	}
}

void main()
{
	int stock_prices[50];
	size_t n = sizeof(stock_prices)/sizeof(int);
	time_t t;
	profitDetails_t result;

	srand((unsigned)time(&t));

	for(int cnt=0; cnt<n; cnt++)
		stock_prices[cnt] = rand() % 1000;
	
	maxProfit(stock_prices, n, &result);

	for(int cnt=0; cnt<n; cnt++)
		printf("%d:%d ", cnt, stock_prices[cnt]);
	
	printf("\nBuy at %d and sell at %d to get max profit of %d\n", result.bIdx, result.sIdx, result.maxProfit);
}
