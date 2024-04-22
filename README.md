# Order book simulation
Highly efficient order book implementation done in OOP fashion and uses min-max heap tree structure.

Key features:
1) Get top-level order for bid ask price in O(1) time complexity.
2) Cancel order in O(1) time complexity using hash map!
3) Adding new price-point in the limit order book takes O(log N).
4) FIFO queue for new orders at particular limit order (price-time priority done right).
5) Tabulating the limit order book that shows aggregating order at the limit price.
6) Market participants basic simulation, places arbitrary orders based on the order book imbalance.

An order book is a crucial component in financial markets, serving as a real-time ledger that displays a list of buy and sell orders for a specific financial instrument. It organizes and presents these orders based on price and quantity, providing traders with essential information to make informed decisions.

Why is it Important?
1) Price Discovery: The order book helps in determining the fair market price by aggregating buy and sell orders. It reflects the supply and demand dynamics, allowing traders to gauge the market sentiment and make price predictions.
2) Transparency: It offers transparency by displaying all active orders, enabling traders to see the depth of the market and understand the liquidity available at different price levels. This transparency fosters trust and confidence in the market.
3) Order Execution: Traders use the order book to place, modify, or cancel orders. It facilitates efficient order matching by automatically pairing buy and sell orders based on predefined criteria, ensuring timely and fair execution.
4) Risk Management: By providing a clear view of market activity, the order book helps traders manage risks effectively. They can assess potential price movements, set stop-loss or take-profit levels, and adjust their trading strategies accordingly.
5) Algorithmic Trading: For algorithmic traders and quantitative analysts, the order book serves as a valuable data source for developing and backtesting trading strategies. It offers granular insights into market microstructure and order flow, which are essential for algorithmic decision-making.




