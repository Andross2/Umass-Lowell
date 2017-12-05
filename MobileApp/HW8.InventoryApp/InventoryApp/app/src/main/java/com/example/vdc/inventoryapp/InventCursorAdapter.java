package com.example.vdc.inventoryapp;

import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CursorAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.bumptech.glide.Glide;

import static com.example.vdc.inventoryapp.R.drawable.ic_placeholder;
import static com.example.vdc.inventoryapp.database.InventoryContract.InventoryEntry;


/**
 * Created by VDC on 11/4/2017.
 */

public class InventCursorAdapter extends CursorAdapter {

    private static final String TAG = InventCursorAdapter.class.getSimpleName();


    protected InventCursorAdapter(Context context, Cursor c) {
        super(context, c, 0);
    }

    @Override
    public View newView(Context context, Cursor cursor, ViewGroup parent) {
        return LayoutInflater.from(context).inflate(R.layout.inventory_item, parent, false);

    }

    @Override
    public void bindView(View view, final Context context, Cursor cursor) {
        TextView product_name = (TextView) view.findViewById(R.id.invent_item_name_text);
        TextView product_quantity = (TextView) view.findViewById(R.id.item_invent_text);
        TextView product_price = (TextView) view.findViewById(R.id.item_price_text);
        TextView product_sold = (TextView) view.findViewById(R.id.item_quantity_text);
        ImageView product_thumbnail = (ImageView) view.findViewById(R.id.item_thumbnail);


        int nameColumnIndex = cursor.getColumnIndex(InventoryEntry.COL_NAME);
        int quantityColumnIndex = cursor.getColumnIndex(InventoryEntry.COL_QUANTITY);
        int priceColumnIndex = cursor.getColumnIndex(InventoryEntry.COL_PRICE);
        int thumbnailColumnIndex = cursor.getColumnIndex(InventoryEntry.COL_PICTURE);
        int salesColumnIndex = cursor.getColumnIndex(InventoryEntry.COL_ITEMS_SOLD);

        int id = cursor.getInt(cursor.getColumnIndex(InventoryEntry._ID));
        final String productName = cursor.getString(nameColumnIndex);
        final int quantity = cursor.getInt(quantityColumnIndex);
        final int products_sold = cursor.getInt(salesColumnIndex);
        String productPrice = "Price: $" + cursor.getString(priceColumnIndex);
        Uri thumbUri = Uri.parse(cursor.getString(thumbnailColumnIndex));

        String productQuantity = "In Stock: " + String.valueOf(quantity) ;
        String productSold = "Sold: "+  String.valueOf(products_sold);

        final Uri currentProductUri = ContentUris.withAppendedId(InventoryEntry.CONTENT_URI, id);

        product_name.setText(productName);
        product_quantity.setText(productQuantity);
        product_price.setText(productPrice);
        product_sold.setText(productSold);
        //We use Glide to import photo images
        Glide.with(context).load(thumbUri)
                .placeholder(R.mipmap.ic_launcher)
                .error(ic_placeholder)
                .crossFade()
                .centerCrop()
                .into(product_thumbnail);

        // Sold button
        final Button bt_sold = (Button)view.findViewById(R.id.bt_sold);
        bt_sold.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                Log.d(TAG, productName + " quantity= " + quantity);
                ContentResolver resolver = view.getContext().getContentResolver();
                ContentValues values = new ContentValues();
                if (quantity > 0) {
                    int qq = quantity;
                    int yy = products_sold;
                    Log.d(TAG, "new quantity= " + qq);
                    values.put(InventoryEntry.COL_QUANTITY, --qq);
                    values.put(InventoryEntry.COL_ITEMS_SOLD, ++yy);
                    resolver.update(
                            currentProductUri,
                            values,
                            null,
                            null
                    );
                    context.getContentResolver().notifyChange(currentProductUri, null);
                } else {
                    Toast.makeText(context, "Out of stock", Toast.LENGTH_SHORT).show();
                }
            }
        });



    }
}
