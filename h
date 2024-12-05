import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression

# Sample dataframe
data = {
    "date": pd.date_range(start="2024-01-01", periods=10),
    "category_1": ["A"] * 5 + ["B"] * 5,
    "category_2": ["X", "X", "Y", "Y", "Y", "X", "X", "Y", "Y", "Y"],
    "metric": [1, 2, 3, 4, 5, 5, 4, 3, 2, 1],
}

df = pd.DataFrame(data)

# Ensure date is numeric for regression
df["date_ordinal"] = df["date"].map(lambda x: x.toordinal())

# Function to calculate slope for each group
def calculate_slope(group):
    X = group["date_ordinal"].values.reshape(-1, 1)  # Independent variable
    y = group["metric"].values  # Dependent variable
    model = LinearRegression()
    model.fit(X, y)
    return model.coef_[0]  # Slope of the regression line

# Group by categories and apply the function
result = (
    df.groupby(["category_1", "category_2"])
    .apply(calculate_slope)
    .reset_index(name="slope")
)

# Display the result
print(result)